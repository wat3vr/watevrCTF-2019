import struct
import hashlib

# The hash functionality, ported to python
def transaction(fr, to, am):
    content_buf = struct.pack(">iif", fr, to, am)
    cont_hashed = hashlib.sha512(content_buf).digest()

    return cont_hashed

def cr_acc(acc, passwd):
    content_buf = struct.pack(">iBBBBBBBBBBBBBBBB", acc, *passwd)
    cont_hashed = hashlib.sha512(content_buf).digest()

    return cont_hashed

def mine(acc):
    content_buf = struct.pack(">i", acc)
    cont_hashed = hashlib.sha512(content_buf).digest()

    return cont_hashed

def block(prev, con):
    block_buf = bytes(list(con) + list(prev))
    block_hash = hashlib.sha512(block_buf).digest()
    block_hash_hex = hashlib.sha512(block_buf).hexdigest()

    if "6" in block_hash_hex:
        block_hash = bytes(list(block_hash) + [block_hash_hex.index("6")])
    else:
        block_hash = bytes(list(block_hash) + [0])

    return block_hash

PASS_CHARS = [0] + list(range(65, 65 + 26))

def pass_gen(length):
    if length == 0:
        yield []
    else:
        for end in pass_gen(length - 1):
            for extra in PASS_CHARS:
                yield [extra] + end

def solve(prev, from_account, amount, needed):
    res = []

    receiver = -1
    while amount < needed:
        receiver += 1
        for password in pass_gen(16):
            wrong = False
            for i in range(15):
                if password[i] == 0 and password[i+1] != 0:
                    wrong = True
                    break
            if wrong:
                continue

            bl = block(prev, cr_acc(receiver, password))
            bl = block(bl, transaction(from_account, receiver, amount))

            if "6" not in bl[:-1].hex():
                res.append((receiver, password, amount))

                prev = bl

                prev = block(prev, transaction(receiver, from_account, amount))

                amount *= 2

                break

    return (res, prev)

if __name__ == "__main__":
    from_account = 0x123

    prev = bytes([0 for _ in range(65)])

    prev = block(prev, cr_acc(from_account, [0 for _ in range(16)]))
    prev = block(prev, mine(from_account))

    amount = 5.2

    for (receiver, password, amount) in solve(prev, from_account, 5.2, 30)[0]:

        print("Create account", hex(receiver), "password:")
        for c in password:
            if c == 0:
                break
            else:
                print(chr(c), end="")
        print()

        print("Send", amount, "to:", receiver, "=", hex(receiver))

        print("Send back")
