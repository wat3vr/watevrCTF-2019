dan_nums = [
    "en",
    "to",
    "tre",
    "fire",
    "fem",
    "seks",
    "syv",
    "otte",
    "ni",
    "ti",
    "elleve",
    "tolv",
    "tretten",
    "fjorten",
    "femten",
    "seksten",
    "sytten",
    "atten",
    "nitten",
    "tyve",
    "énogtyve",
    "toogtyve",
    "treogtyve",
    "fireogtyve",
    "femogtyve",
    "seksogtyve",
    "syvogtyve",
    "otteogtyve",
    "niogtyve",
    "tredive",
    "énogtredive",
    "toogtredive",
    "treogtredive",
    "fireogtredive",
    "femogtredive",
    "seksogtredive",
    "syvogtredive",
    "otteogtredive",
    "niogtredive",
    "fyrre",
    "énogfyrre",
    "toogfyrre",
    "treogfyrre",
    "fireogfyrre",
    "femogfyrre",
    "seksogfyrre",
    "syvogfyrre",
    "otteogfyrre",
    "niogfyrre",
    "halvtreds",
    "énoghalvtreds",
    "tooghalvtreds",
    "treoghalvtreds",
    "fireoghalvtreds",
    "femoghalvtreds",
    "seksoghalvtreds",
    "syvoghalvtreds",
    "otteoghalvtreds",
    "nioghalvtreds",
    "tres",
    "énogtres",
    "toogtres",
    "treogtres",
    "fireogtres",
    "femogtres",
    "seksogtres",
    "syvogtres",
    "otteogtres",
    "niogtres",
    "halvfjerds",
    "énoghalvfjerds",
    "tooghalvfjerds",
    "treoghalvfjerds",
    "fireoghalvfjerds",
    "femoghalvfjerds",
    "seksoghalvfjerds",
    "syvoghalvfjerds",
    "otteoghalvfjerds",
    "nioghalvfjerds",
    "firs",
    "énogfirs",
    "toogfirs",
    "treogfirs",
    "fireogfirs",
    "femogfirs",
    "seksogfirs",
    "syvogfirs",
    "otteogfirs",
    "niogfirs",
    "halvfems",
    "énoghalvfems",
    "tooghalvfems",
    "treoghalvfems",
    "fireoghalvfems",
    "femoghalvfems",
    "seksoghalvfems",
    "syvoghalvfems",
    "otteoghalvfems",
    "nioghalvfems",
    "hundrede",
]

def parse_add(question):
    question = question + ["plus"]
    acc = 0

    op = 1
    so_far = []
    for word in question:
        if word == "plus":
            acc += op * parse_mul(so_far)
            so_far = []
            op = 1
        elif word == "minus":
            acc += op * parse_mul(so_far)
            so_far = []
            op = -1
        else:
            so_far += [word]

    return acc

def parse_mul(question):
    question = question + ["gange"]
    acc = 1

    op = 1
    so_far = []
    for word in question:
        if word == "gange":
            acc *= parse_num(so_far) ** op
            so_far = []
            op = 1
        elif word == "divideret":
            acc *= parse_num(so_far) ** op
            so_far = []
            op = -1
        elif word != "med":
            so_far += [word]

    return int(acc)

def parse_num(question):
    if len(question) == 1:
        return 1+dan_nums.index(question[0])
    else:
        raise Exception("No such number " + " ".join(question))

def solve(q):
    return dan_nums[parse_add(q.split(" ")) - 1]

if __name__ == "__main__":
    while True:
        print(solve(input("> ")))
