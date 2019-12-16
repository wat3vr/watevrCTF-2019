import socket, threading
import sys, os
import random, signal

PORT = 1337
KEY = random.randint(0, 100000000000000000000000)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((socket.gethostname(), PORT))
s.listen(5)
client_list = []

def relay_message(message, sender):
	global client_list
	for client in client_list:
		if client != sender:
			try:
				client[0].send(message)
			except:
				client[0].close()
				client_list.remove(client)

def client_reciever(socket):
	print(socket)
	while True:
		message = socket[0].recv(500000)
		if not message:
			break
		print("Message from: " + socket[1][0] + "\nContent: " + message.decode("utf-8"))
		relay_message(message, socket)

def main():
	while True:
		client, address = s.accept() # accept all incomming clients
		client_list.append((client, address))
		print("Incomming user: " + address[0])
		client.send(bytes("KEY: " + str(KEY), "utf-8"))
		client_thread = threading.Thread(target=client_reciever, args=((client, address), ))
		client_thread.start()

#this is only for closing the sockets after sigsegv
def handler_signals(signum, frame):
	global run
	global s
	s.close()
	print("----Closed Server----")
	sys.exit()
signal.signal(signal.SIGINT, handler_signals)
signal.signal(signal.SIGTERM, handler_signals)
#this is only for closing the sockets after sigsegv

main()
