from z3 import *

s = Solver()

response_body = [BitVec(str(i), 32) for i in range(36)]
target_path = b"i_store_my_flag_inside_this_file.txt"
flag = b"watevr{0bj3c71v3ly_superior_70_h77p}"

for char in response_body:
    s.add(char == char & 0xff)

# Flag prefix
s.add(target_path[0] == response_body[0] ^ flag[0] ^ target_path[0])
s.add(target_path[1] == response_body[1] ^ flag[1] ^ target_path[1])
s.add(target_path[2] == response_body[2] ^ flag[2] ^ target_path[2])
s.add(target_path[3] == response_body[3] ^ flag[3] ^ target_path[3])
s.add(target_path[4] == response_body[4] ^ flag[4] ^ target_path[4])
s.add(target_path[5] == response_body[5] ^ flag[5] ^ target_path[5])
s.add(target_path[6] == response_body[6] ^ flag[6] ^ target_path[6])

# Flag content
s.add(target_path[7] == (response_body[7] - flag[7] + target_path[7]) % 256)
s.add(target_path[8] == (response_body[8] - flag[8] + target_path[8]) % 256)
s.add(target_path[9] == (response_body[9] - flag[9] + target_path[9]) % 256)
s.add(target_path[10] == (response_body[10] - flag[10] + target_path[10]) % 256)

s.add(target_path[11] == response_body[14] ^ flag[14] ^ target_path[11])
s.add(target_path[12] == response_body[13] ^ flag[13] ^ target_path[12])
s.add(target_path[13] == response_body[12] ^ flag[12] ^ target_path[13])
s.add(target_path[14] == response_body[11] ^ flag[11] ^ target_path[14])

num = (
    (response_body[18] << 24 | response_body[17] << 16 | response_body[16] << 8 | response_body[15])
    - (flag[18] << 24 | flag[17] << 16 | flag[16] << 8 | flag[15])
    + (target_path[18] << 24 | target_path[17] << 16 | target_path[16] << 8 | target_path[15])
)
s.add(target_path[15] == num & 0xFF)
s.add(target_path[16] == (num >> 8) & 0xFF)
s.add(target_path[17] == (num >> 16) & 0xFF)
s.add(target_path[18] == (num >> 24) & 0xFF)

s.add(target_path[19] == (
    (((response_body[22] & 1) << 7) | (response_body[19] >> 1))
    ^ 185
    ^ target_path[19]
))
s.add(target_path[20] == (
    (((response_body[19] & 1) << 7) | (response_body[20] >> 1))
    ^ 186
    ^ target_path[20]
))
s.add(target_path[21] == (
    (((response_body[20] & 1) << 7) | (response_body[21] >> 1))
    ^ 184
    ^ target_path[21]
))
s.add(target_path[22] == (
    (((response_body[21] & 1) << 7) | (response_body[22] >> 1))
    ^ 50
    ^ target_path[22]
))

s.add(target_path[23] == (
    (((response_body[26] & 0xF) << 4) | (response_body[23] >> 4))
    ^ 39
    ^ target_path[23]
))
s.add(target_path[24] == (
    (((response_body[23] & 0xF) << 4) | (response_body[24] >> 4))
    ^ 38
    ^ target_path[24]
))
s.add(target_path[25] == (
    (((response_body[24] & 0xF) << 4) | (response_body[25] >> 4))
    ^ 150
    ^ target_path[25]
))
s.add(target_path[26] == (
    (((response_body[25] & 0xF) << 4) | (response_body[26] >> 4))
    ^ 247
    ^ target_path[26]
))

s.add(target_path[27] == response_body[29] ^ flag[29] ^ target_path[27])
s.add(target_path[28] == response_body[30] ^ flag[30] ^ target_path[28])
s.add(target_path[29] == response_body[27] ^ flag[27] ^ target_path[29])
s.add(target_path[30] == response_body[28] ^ flag[28] ^ target_path[30])

s.add(target_path[31] == response_body[31] ^ flag[31] ^ target_path[31])
s.add(target_path[32] == response_body[32] ^ flag[32] ^ target_path[32])
s.add(target_path[33] == response_body[33] ^ flag[33] ^ target_path[33])
s.add(target_path[34] == response_body[34] ^ flag[34] ^ target_path[34])

# Flag suffix
s.add(target_path[35] == response_body[35] ^ flag[35] ^ target_path[35])


result = s.check()
print(result)

while result == sat:
    model = s.model()
    result_array = [0] * 36

    for d in model.decls():
        result_array[int(d.name())] = model[d].as_long()

    print("".join(chr(i) for i in result_array))

    s.add(Or(*[response_body[i] != result_array[i] for i in range(36)]))
    result = s.check()
