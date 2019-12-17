import sympy as sp

def convert_string_to_int_array(string):
    out = []
    for char in string:
        out.append(ord(char))
    return out

def parse(expression, length):
    output = ""
    for x in range(length):
        ##Replaces variable with number
        string = expression.replace("x", str(x))
        output += chr(int(sp.N(string)))
    return output

def lagrange_interpolation(intersections):
    function = ""
    for x in range(len(intersections)):
        y = intersections[x]
        acc = 1
        factor = ""
        for i in range(len(intersections)):
            if i != x:
                factor += "*(x-" + str(i) + ")"
                acc *= (x-i)
        coef = str(y) + "/" + str(acc)
        function += "+" + coef + factor
    function = function[1:]
    return function

flag = input("")
f = open("polly.txt", "r").read()
if parse(str(sp.expand(lagrange_interpolation(convert_string_to_int_array(flag)))), len(flag)) == parse(str(f), len(flag)):
    print("success")
    exit(0)
else:
    exit(1)
