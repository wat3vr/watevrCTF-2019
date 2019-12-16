#!/usr/bin/env python3

# request and response in this file refer to the HTTP specification, they are reversed for HTJP
import sys
import re
import base64
from urllib.parse import quote
import signal

def interrupted(signum, frame):
    exit()


signal.signal(signal.SIGALRM, interrupted)
signal.alarm(5)

debug = False
max_length = 1024 * 16

f = open("flag.txt")
flag = [ord(c) for c in f.read()]
f.close()
target_path = [c for c in b"i_store_my_flag_inside_this_file.txt"]

chars = 0


def get_line():
    global chars

    line = b""
    while not line.endswith(b"\r\n") and chars <= max_length:
        line += sys.stdin.buffer.read(1)

    return line[0:-2]

while True:

    status_line = get_line()
    if status_line != b"HTTP/1.1 200 OK":
        exit()

    headers = b""
    header = get_line()
    body_length = None
    while header:
        match = re.match(rb"(.+):(.+)", header)
        if not match:
            exit()

        if match.group(1) == b"Content-Length":
            body_length = int(match.group(2))
        else:
            headers += header

        header = get_line()

    if body_length is None:
        exit()

    body = sys.stdin.buffer.read(min(body_length, max_length - chars))

    encoded_headers = base64.b64encode(headers)

    response_body = [c for c in body or ""]
    if len(response_body) < len(flag):
        response_body += [0] * (len(flag) - len(response_body))
    request_path_decoded = list(response_body)

    # Flag prefix
    request_path_decoded[0] = response_body[0] ^ flag[0] ^ target_path[0]
    request_path_decoded[1] = response_body[1] ^ flag[1] ^ target_path[1]
    request_path_decoded[2] = response_body[2] ^ flag[2] ^ target_path[2]
    request_path_decoded[3] = response_body[3] ^ flag[3] ^ target_path[3]
    request_path_decoded[4] = response_body[4] ^ flag[4] ^ target_path[4]
    request_path_decoded[5] = response_body[5] ^ flag[5] ^ target_path[5]
    request_path_decoded[6] = response_body[6] ^ flag[6] ^ target_path[6]

    # Flag content
    request_path_decoded[7] = (response_body[7] - flag[7] + target_path[7]) % 256
    request_path_decoded[8] = (response_body[8] - flag[8] + target_path[8]) % 256
    request_path_decoded[9] = (response_body[9] - flag[9] + target_path[9]) % 256
    request_path_decoded[10] = (
        response_body[10] - flag[10] + target_path[10]
    ) % 256

    request_path_decoded[11] = response_body[14] ^ flag[14] ^ target_path[11]
    request_path_decoded[12] = response_body[13] ^ flag[13] ^ target_path[12]
    request_path_decoded[13] = response_body[12] ^ flag[12] ^ target_path[13]
    request_path_decoded[14] = response_body[11] ^ flag[11] ^ target_path[14]

    num = (
        (response_body[18] << 24 | response_body[17] << 16 | response_body[16] << 8 | response_body[15])
        - (flag[18] << 24 | flag[17] << 16 | flag[16] << 8 | flag[15])
        + (target_path[18] << 24 | target_path[17] << 16 | target_path[16] << 8 | target_path[15])
    )
    request_path_decoded[15] = num & 0xFF
    request_path_decoded[16] = (num >> 8) & 0xFF
    request_path_decoded[17] = (num >> 16) & 0xFF
    request_path_decoded[18] = (num >> 24) & 0xFF

    request_path_decoded[19] = (
        (((response_body[22] & 1) << 7) | (response_body[19] >> 1))
        ^ 185
        ^ target_path[19]
    )
    request_path_decoded[20] = (
        (((response_body[19] & 1) << 7) | (response_body[20] >> 1))
        ^ 186
        ^ target_path[20]
    )
    request_path_decoded[21] = (
        (((response_body[20] & 1) << 7) | (response_body[21] >> 1))
        ^ 184
        ^ target_path[21]
    )
    request_path_decoded[22] = (
        (((response_body[21] & 1) << 7) | (response_body[22] >> 1))
        ^ 50
        ^ target_path[22]
    )

    request_path_decoded[23] = (
        (((response_body[26] & 0xF) << 4) | (response_body[23] >> 4))
        ^ 39
        ^ target_path[23]
    )
    request_path_decoded[24] = (
        (((response_body[23] & 0xF) << 4) | (response_body[24] >> 4))
        ^ 38
        ^ target_path[24]
    )
    request_path_decoded[25] = (
        (((response_body[24] & 0xF) << 4) | (response_body[25] >> 4))
        ^ 150
        ^ target_path[25]
    )
    request_path_decoded[26] = (
        (((response_body[25] & 0xF) << 4) | (response_body[26] >> 4))
        ^ 247
        ^ target_path[26]
    )

    request_path_decoded[27] = response_body[29] ^ flag[29] ^ target_path[27]
    request_path_decoded[28] = response_body[30] ^ flag[30] ^ target_path[28]
    request_path_decoded[29] = response_body[27] ^ flag[27] ^ target_path[29]
    request_path_decoded[30] = response_body[28] ^ flag[28] ^ target_path[30]

    request_path_decoded[31] = response_body[31] ^ flag[31] ^ target_path[31]
    request_path_decoded[32] = response_body[32] ^ flag[32] ^ target_path[32]
    request_path_decoded[33] = response_body[33] ^ flag[33] ^ target_path[33]
    request_path_decoded[34] = response_body[34] ^ flag[34] ^ target_path[34]

    # Flag suffix
    request_path_decoded[35] = response_body[35] ^ flag[35] ^ target_path[35]

    request_path_decoded = request_path_decoded[0 : len(body or "")]
    request_path = quote("".join(chr(c) for c in request_path_decoded))

    sys.stdout.write(
        f"POST /{request_path} HTTP/1.1\r\nHost: 13.53.207.167\r\nContent-Type: text/plain\r\nContent-Length: {len(encoded_headers)}\r\n\r\n{encoded_headers.decode()}\r\n"
    )
