import math
import requests
from bs4 import BeautifulSoup
import random

flag = input()

### spl program generator

print("generating spl program...")

nums = {}
maxnum = max(len(flag), 255)

for i in range(9):
    nums[2 ** i] = [2 ** i, "init"]


def get_num(num):
    global nums
    while num not in nums:
        old_chars = nums.copy()
        for num1, his1 in old_chars.items():
            for num2, his2 in old_chars.items():
                for op in ["diff", "sum", "prod"]:
                    if op == "diff":
                        result = num1 - num2
                    elif op == "sum":
                        result = num1 + num2
                    elif op == "prod":
                        result = num1 * num2

                    if 0 <= result <= maxnum and result not in nums:
                        nums[result] = [his1, his2, op]

            result = num1 ** 2
            if 0 <= result <= maxnum and result not in nums:
                nums[result] = [his1, "pow"]
    return nums[num]


def construct_shakespeare(history):
    if history[-1] == "diff":
        return "the difference between %s and %s" % (
            construct_shakespeare(history[0]),
            construct_shakespeare(history[1]),
        )
    elif history[-1] == "sum":
        return "the sum of %s and %s" % (
            construct_shakespeare(history[0]),
            construct_shakespeare(history[1]),
        )
    elif history[-1] == "prod":
        return "the product of %s and %s" % (
            construct_shakespeare(history[0]),
            construct_shakespeare(history[1]),
        )
    elif history[-1] == "pow":
        return "the square of %s" % construct_shakespeare(history[0])
    elif history[-1] == "init":
        return "article %snoun" % ("adj " * int(math.log(history[0], 2)))


code = """This is the play that encodes the past.

Romeo, a young programmer from a time long ago.
Juliet, a beautiful woman with a memory disorder. 

                Act I: The beginning.

        Scene I: In a processor, long long ago.

[Enter Romeo and Juliet]

        Scene II: The start of a never ending tale.
"""

numerals = ["I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV","XVI","XVII","XVIII","XIX","XX","XXI","XXII","XXIII","XXIV","XXV","XXVI","XXVII","XXVIII","XXIX","XXX","XXXI","XXXII","XXXIII","XXXIV","XXXV","XXXVI","XXXVII","XXXVIII","XXXIX","XL","XLI","XLII","XLIII","XLIV","XLV","XLVI","XLVII","XLVIII","XLIX","L","LI","LII","LIII","LIV","LV","LVI","LVII","LVIII","LIX","LX","LXI","LXII","LXIII","LXIV","LXV","LXVI","LXVII","LXVIII","LXIX","LXX","LXXI","LXXII","LXXIII","LXXIV","LXXV","LXXVI","LXXVII","LXXVIII","LXXIX","LXXX","LXXXI","LXXXII","LXXXIII","LXXXIV","LXXXV","LXXXVI","LXXXVII","LXXXVIII","LXXXIX","XC","XCI","XCII","XCIII","XCIV","XCV","XCVI","XCVII","XCVIII","XCIX","C"]

scene = 1
counter = 0

for i, char in enumerate(reversed(flag)):
    if (
        scene < len(numerals) - 2
        and random.randint(0, 10 - counter) == 0
        and counter != 0
    ):
        counter = 0
        scene += 1
        code += "\n        Scene %s: The breather.\n" % numerals[scene]

    code += (
        "\nJuliet:\nYou are as adj as %s.\n\nRomeo:\nRemember me.\n"
        % construct_shakespeare(get_num(ord(char) + i))
    )
    counter += 1

code += """
Juliet:
You are as adj as %s.""" % construct_shakespeare(
    get_num(len(flag))
)

code += " We must return to scene II."

code += """

    Scene {0}: The start of something new.

Juliet:
you are as adj as the difference between thyself and article noun.

Romeo:
recall me. You are as adj as the difference between thyself and myself.

Juliet:
Remember me.

Romeo:
Am i better than the difference between article noun and article noun?

Juliet:
If so, we shall proceed to Scene {0}.

[Exeunt]
""".format(
    numerals[scene + 1]
)

### spl prettyfier

articles_list = ["a", "an", "the", "thine", "thy", "your"]

adjective_list = ""
for filename in ["positive", "neutral"]:
    f = open("spl/include/%s_adjective.wordlist" % filename)
    adjective_list += f.read()
    f.close()
adjective_list = adjective_list.split("\n")[:-1]

noun_list = ""
for filename in ["positive", "neutral"]:
    f = open("spl/include/%s_noun.wordlist" % filename)
    noun_list += f.read()
    f.close()
noun_list = noun_list.split("\n")[:-1]

while "article" in code:
    code = code.replace("article", random.choice(articles_list), 1)
while "adj" in code:
    code = code.replace("adj", random.choice(adjective_list), 1)
while "noun" in code:
    code = code.replace("noun", random.choice(noun_list), 1)

prettified_code = []

for line in code.split("\n"):
    counter = 0
    last_whitespace = None
    line = list(line)
    for i, char in enumerate(line):
        counter += 1
        if char == " ":
            last_whitespace = i
        if counter >= 60:
            line[last_whitespace] = "\n"
            counter = i - last_whitespace
    prettified_code.append("".join(line))

prettified_code = "\n".join(prettified_code)


print("saving spl program...")
f = open("downloads/romeo", "w")
f.write(prettified_code)
f.close()

print("done")
