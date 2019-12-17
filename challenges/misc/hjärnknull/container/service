#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import signal

def interrupted(signum, frame):
    print("timeout")
    exit()


signal.signal(signal.SIGALRM, interrupted)
signal.alarm(20)

kåd = [] # fält som består av [instructions, arguements]
stack = [] # fält med pekare till kåd
data = [1]*1000 # fält med data element

TESTLÄGE = False
challenges = [x.rstrip("\n") for x in open("/home/ctf/challenge_file.txt", "r").readlines()]
current_challenge = 0
fetch_phase = 0
score = 0

#"server sided"
def validate_answare(answare):
    global fetch_phase
    global challenges
    global current_challenge
    global score
    if str(answare) == str(challenges[current_challenge].split(":")[1]):
        score += 1
        current_challenge += 1
    else:
        print("Ledsen asså men ditt program funkar helt enkelt inte :/")
        exit(0)
    if score > 3:
        print("J\xe4vlar vilket klockrent program du har skrivit! H\xe4r har du en flagga " + "".join(open("/home/ctf/flag.txt", "r").readlines()).rstrip("\n"))
        exit(0)
def take_input_from_server():
    global fetch_phase
    global challenges
    global current_challenge
    serv_resp = int(str(challenges[current_challenge].split(":")[0]).split(" ")[fetch_phase]) # ta fetch_phase position från input listan
    if fetch_phase == 2:
        fetch_phase = 0
    else:
        fetch_phase += 1
    return serv_resp
#"client sided"
def testkör(ip, endip):
    while ip != endip:
        op = kåd[ip][0].lower()
        args = kåd[ip][1]
        #print(ip, op, args)
        if op == "eller":
            data[args[0]] = data[args[0]] | data[args[1]]
        elif op == "inte":
            data[args[0]] = ~data[args[0]]
        elif op == "testa":
            if data[args[0]] == data[args[1]]:
                stack.append(ip)
                ip = args[2]
                continue
        elif op == "poppa":
            ip = stack.pop()
        elif op == "in":
            data[args[0]] = int(input())
        elif op == "ut":
            print(data[args[0]])
        elif op == "hsh":
            data[args[0]] = data[args[0]] >> data[args[1]]
        elif op == "vsh":
            data[args[0]] = data[args[0]] << data[args[1]]
        ip += 1
def kör(ip, endip):
    while ip != endip:
        op = kåd[ip][0].lower()
        args = kåd[ip][1]
        #print(ip, op, args)
        if op == "eller":
            data[args[0]] = data[args[0]] | data[args[1]]
        elif op == "inte":
            data[args[0]] = ~data[args[0]]
        elif op == "testa":
            if data[args[0]] == data[args[1]]:
                stack.append(ip)
                ip = args[2]
                continue
        elif op == "poppa":
            ip = stack.pop()
        elif op == "in":
            data[args[0]] = take_input_from_server()
        elif op == "ut":
            validate_answare(data[args[0]])
        elif op == "hsh":
            data[args[0]] = data[args[0]] >> data[args[1]]
        elif op == "vsh":
            data[args[0]] = data[args[0]] << data[args[1]]
        ip += 1
def main():
    print("Welcome to hj\xe4rnknull!")
    print("Hj\xe4rnknull is the most useful language that has ever been written!")
    print('Syntax: "instruction argument1 argument2 ..."')
    print("valid instructions are: eller, inte, hsh, vsh, testa, poppa, in, ut. End program with slut")
    loc = 0
    while True:
        tmpkåd = str(input(str(loc) + ": ")).split(" ")
        kåd.append([tmpkåd[0], [int(x) for x in tmpkåd[1:]]])
        if "slut" in str(kåd):
            break;
        loc += 1
    if TESTLÄGE:
        testkör(0, loc)
    else:
        kör(0, loc)
main()
