import socket, select, signal, string
import sys, os, time, random
import threading

HOST = '198.51.100.0'
PORT = 1337
USERNAME = "Houdini"

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((socket.gethostname(), PORT))
key = int(s.recv(1240).decode("utf-8").split(" ")[1])

def encrypt(plaintext):
	global USERNAME
	global key
	plaintext = USERNAME + ": " + plaintext
	out = [random.randint(0, 9999), random.randint(0, 999)]
	for i in range(len(plaintext)):
		out.append((out[i+1] + ((out[i] * ord(plaintext[i])) ^ (key+out[i+1]))) ^ (key*out[i]))
