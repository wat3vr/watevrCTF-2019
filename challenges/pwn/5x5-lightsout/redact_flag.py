import sys
path_in = sys.argv[1]
path_out = sys.argv[2]

REDACT_STRING = b"REDACTED_"

binary = open(path_in, "rb").read()

if b"watevr{" not in binary:
    print("Could not find flag")
    exit()

flag_start = binary.index(b"watevr{")
print("Flag at", hex(flag_start))

flag_end = 1 + flag_start + binary[flag_start:].index(b"}")

print("Flag end:", hex(flag_end))

cont_start = flag_start + len(b"watevr{")
cont_end = flag_end - len(b"}")

print("Content", hex(cont_start), ":", hex(cont_end))

redact_times = 1 + (cont_end - cont_start) // len(REDACT_STRING)
redact = (REDACT_STRING * redact_times)[:cont_end - cont_start]

print("Redact:", redact)

out = binary[:cont_start] + redact + binary[cont_end:]

open(path_out, "wb").write(out)
print("Done")
