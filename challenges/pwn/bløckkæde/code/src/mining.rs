use rand::prelude::*;

const DANISH_NUMBERS: &[&str] = &[
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
];

pub fn parse_danish(inp: &str) -> Option<u64> {
    for (i, x) in DANISH_NUMBERS.iter().enumerate() {
        if x == &inp {
            return Some(1 + i as u64);
        }
    }
    None
}

pub fn into_danish(n: u64) -> &'static str {
    DANISH_NUMBERS[n as usize - 1]
}

fn gen_number() -> (String, u64) {
    let n = thread_rng().gen_range(0, 100);
    (DANISH_NUMBERS[n].to_string(), 1 + n as u64)
}

pub fn generate_problem(diff: usize) -> (String, u64) {
    loop {
        let prob = generate_math_problem_add();
        let nr_words = prob.0.split_whitespace().count();

        if nr_words == 2 * diff + 1 {
            return prob;
        }
    }
}

fn generate_math_problem_add() -> (String, u64) {
    let op_n = thread_rng().gen_range(0, 4);
    match op_n {
        0 | 1 => generate_math_problem_mul(),
        2 => {
            let (a, an) = generate_math_problem_add();
            let (b, bn) = generate_math_problem_mul();

            if an + bn > 100 {
                generate_math_problem_add()
            } else {
                (format!("{} plus {}", a, b), an + bn)
            }
        }
        3 => {
            let (a, an) = generate_math_problem_add();
            let (b, bn) = generate_math_problem_mul();

            if an - bn > 100 {
                generate_math_problem_add()
            } else {
                (format!("{} minus {}", a, b), an - bn)
            }
        }
        _ => unreachable!(),
    }
}

pub fn generate_math_problem_mul() -> (String, u64) {
    let op_n = thread_rng().gen_range(0, 3);
    match op_n {
        0 => gen_number(),
        1 => {
            let (a, an) = gen_number();
            let (b, bn) = gen_number();

            if an * bn > 100 {
                generate_math_problem_mul()
            } else {
                (format!("{} gange {}", a, b), an * bn)
            }
        }
        2 => {
            let (a, an) = gen_number();
            let (b, bn) = gen_number();

            if bn == 0 || an / bn > 100 || an % bn != 0 {
                generate_math_problem_mul()
            } else {
                (format!("{} divideret med {}", a, b), an / bn)
            }
        }
        _ => unreachable!(),
    }
}
