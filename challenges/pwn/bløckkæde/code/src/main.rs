#![feature(non_ascii_idents)]

use std::io::{stdin, Stdin, Result as IResult};

use rand::prelude::*;

mod kæde;
mod mining;

use kæde::*;
use mining::*;

enum State {
    LoggedInTo(AccøuntID),
    NotLoggedIn,
}

const FLAG: Option<&'static str> = option_env!("FLAGG");

fn main() -> IResult<()> {
    let mut chain = BløckKæde::default();

    let mut stdin = stdin();
    let mut state = State::NotLoggedIn;

    loop {
        match state {
            State::NotLoggedIn => {
                println!("(1) - Log in");
                println!("(2) - Create account");
                println!("(3) - Show all accounts balance");
                println!("(4) - Exit");
                let mut inp = String::new();
                stdin.read_line(&mut inp)?;
                match inp.trim_end() {
                    "1" => {
                        println!("Account nr in hex:");
                        let mut inp = String::new();
                        stdin.read_line(&mut inp)?;
                        let nr = u64::from_str_radix(&inp.trim_end(), 16);
                        if let Ok(x) = nr {
                            println!("Password:");
                            let mut pass = String::new();
                            stdin.read_line(&mut pass)?;
                            let pass = pass.trim_end();

                            if pass.len() > 16 {
                                println!("Too long!");
                                continue;
                            }
                            let mut pass_a = [0; 16];
                            for i in 0..pass.len() {
                                pass_a[i] = pass.as_bytes()[i] as u8;
                            }
                            let mut logged_in = false;
                            for (a, p) in chain.get_account_list() {
                                if a.0 == x && p.0 == pass_a {
                                    state = State::LoggedInTo(a);
                                    logged_in = true;
                                }
                            }

                            if !logged_in {
                                println!("Wrong name/password!");
                            }
                        } else {
                            println!("Not a hex number!");
                        }
                    }
                    "2" => {
                        println!("Account nr in hex:");
                        let mut inp = String::new();
                        stdin.read_line(&mut inp)?;
                        let nr = u64::from_str_radix(&inp.trim_end(), 16);
                        if let Ok(x) = nr {
                            println!("Password:");
                            let mut pass = String::new();
                            stdin.read_line(&mut pass)?;
                            let pass = pass.trim_end();

                            if pass.len() > 16 {
                                println!("Too long!");
                                continue;
                            }
                            let mut pass_a = [0; 16];
                            for i in 0..pass.len() {
                                pass_a[i] = pass.as_bytes()[i] as u8;
                            }
                            chain.add_bløck(BløckContent::CrætedAccøunt(
                                AccøuntID(x),
                                Passwørd(pass_a),
                            ));
                        } else {
                            println!("Not a hex number!");
                        }
                    }
                    "3" => show_balances(&chain),
                    "4" => return Ok(()),
                    "" => {}
                    _ => println!("Unknown action"),
                }
            }
            State::LoggedInTo(acc) => {
                println!(
                    "Logged in to {:x}; balance: {:.6}",
                    acc.0,
                    chain.get_account_money(acc)
                );
                println!("(1) - Do transaction");
                println!("(2) - Mine");
                println!("(3) - Buy flag");
                println!("(4) - Log out");
                let mut inp = String::new();
                stdin.read_line(&mut inp)?;
                match inp.trim_end() {
                    "1" => {
                        println!("Receiver nr in hex:");
                        let mut inp = String::new();
                        stdin.read_line(&mut inp)?;
                        let nr = u64::from_str_radix(&inp.trim_end(), 16);
                        if let Ok(x) = nr {
                            println!("Amount:");
                            let mut inp = String::new();
                            stdin.read_line(&mut inp)?;
                            let nr = inp.trim_end().parse::<f32>();
                            if let Ok(y) = nr {
                                if y > 0. {
                                    chain.add_bløck(BløckContent::Transacksjon(
                                        acc,
                                        AccøuntID(x),
                                        y,
                                    ));
                                } else {
                                    println!("Positive numbers only");
                                }
                            } else {
                                println!("Invalid number");
                            }
                        } else {
                            println!("Not a hex number!");
                        }
                    }
                    "2" => {
                        if proof_of_work(&mut stdin)? {
                            chain.add_bløck(BløckContent::Mine(acc));
                        }
                    }
                    "3" => {
                        if chain.get_account_money(acc) < FLAG_COST {
                            println!("You need {:.2} to buy the flag!", FLAG_COST);
                        } else {
                            println!("{}", FLAG.unwrap_or("REDACTED"));
                            return Ok(());
                        }
                    }
                    "4" => {
                        state = State::NotLoggedIn;
                    }
                    "" => {}
                    _ => println!("Unknown action"),
                }
            }
        }
    }
}

fn show_balances(ch: &BløckKæde) {
    for (acc, _) in ch.get_account_list() {
        let amount = ch.get_account_money(acc);
        println!("\t0x{:x} - {:.6}", acc.0, amount);
    }
}

fn proof_of_work(s: &mut Stdin) -> IResult<bool> {
    for i in 0..4 {
        let diff = i as isize + thread_rng().gen_range(0, 3);

        let diff = diff.max(1).min(6);
        let (prob, sol) = generate_problem(diff as usize);
        println!("\nProblem {}/4", i + 1);
        println!("{}?", prob);

        let mut inp = String::new();
        s.read_line(&mut inp)?;
        let nr = parse_danish(inp.trim_end());

        if nr == Some(sol) {
            println!("Good job!");
        } else {
            println!("Wrong. Was {}", into_danish(sol));
            return Ok(false);
        }
    }
    Ok(true)
}
