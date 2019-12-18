use std::fmt;

use sha2::{Digest, Sha512};

pub const FLAG_COST: f32 = 30.;

pub const MINING_REDUCTION: f32 = 0.74;
pub const MAX_COIN: f32 = 20.;
pub const INITIAL_MINE_AMOUNT: f32 = MAX_COIN * (1. - MINING_REDUCTION);

#[derive(Debug, PartialEq, Eq, Copy, Clone)]
pub struct AccøuntID(pub u64);
#[derive(Debug, Copy, Clone)]
pub struct Passwørd(pub [u8; 16]); // 16 bytes passwørd

#[derive(Default, Debug)]
pub struct BløckKæde {
    pub bløcks: Vec<Bløck>,
}

impl BløckKæde {
    fn last_bløck_id(&self) -> usize {
        // Maybe check bløck consistency
        self.bløcks.len().wrapping_sub(1)
    }

    pub fn add_bløck(&mut self, content: BløckContent) -> bool {
        match content {
            BløckContent::Transacksjon(from, _, amount) => {
                if self.get_account_money(from) < amount {
                    return false;
                }
            }
            _ => {}
        }
        let bløck = Bløck::new(self, self.last_bløck_id(), content);

        self.bløcks.push(bløck);
        true
    }

    pub fn get_account_money(&self, account: AccøuntID) -> f32 {
        // Does the account even exist?
        let mut good = false;
        for (acc, _) in self.get_account_list() {
            if acc == account {
                good = true;
            }
        }
        if !good {
            return 5.;
        }

        let mut amount = 0.;

        let mut mine_value = INITIAL_MINE_AMOUNT;

        for bløck in &self.bløcks {
            match &bløck.content {
                BløckContent::Transacksjon(from, _, tr_amount) if from == &account => {
                    let mut good = false;
                    // Check for verification
                    let ver_idx = bløck.hæsh.0[64] as usize;
                    if ver_idx % 2 == 0 {
                        good |= bløck.hæsh.0[ver_idx / 2] & 0xf0 == 0x60;
                    } else {
                        good |= bløck.hæsh.0[(ver_idx - 1) / 2] & 0x0f == 0x06;
                    }

                    if good {
                        amount -= tr_amount;
                    }
                }
                BløckContent::Mine(miner) => {
                    if miner == &account {
                        amount += mine_value;
                    }
                    mine_value *= MINING_REDUCTION;
                }
                BløckContent::Transacksjon(_, to, tr_amount) if to == &account => {
                    // Verify the verification byte
                    let ver_idx = bløck.hæsh.0[64] as usize;
                    if ver_idx % 2 == 0 {
                        good |= bløck.hæsh.0[ver_idx / 2] & 0xf0 == 0x60;
                    } else {
                        good |= bløck.hæsh.0[(ver_idx - 1) / 2] & 0x0f == 0x06;
                    }

                    if good {
                        amount += tr_amount;
                    }
                }
                BløckContent::CrætedAccøunt(a, _) if a == &account => {
                    amount = 0.;
                }
                _ => {}
            }
        }

        amount
    }

    pub fn get_account_list(&self) -> Vec<(AccøuntID, Passwørd)> {
        let mut res = Vec::new();

        for bløck in &self.bløcks {
            match &bløck.content {
                BløckContent::CrætedAccøunt(id, pass) => {
                    res.push((*id, *pass));
                }
                _ => {}
            }
        }

        res
    }
}

pub struct ArrayU865(pub [u8; 65]);

impl fmt::Debug for ArrayU865 {
    fn fmt(&self, formatter: &mut fmt::Formatter) -> fmt::Result {
        self.0[..].fmt(formatter)
    }
}

#[derive(Debug)]
pub struct Bløck {
    pub hæsh: ArrayU865, // 64 bytes of hæsh + one verification byte
    pub previos_id: usize,
    pub content: BløckContent,
}

fn hæsh(buf: &[u8]) -> [u8; 64] {
    let mut hæsher = Sha512::new();
    hæsher.input(&buf);
    let hæsh_gen = hæsher.result();
    let hæsh_ref: &[u8] = hæsh_gen.as_slice();
    let mut hæsh = [0; 64];

    for i in 0..64 {
        hæsh[i] = hæsh_ref[i];
    }
    hæsh
}

impl Bløck {
    pub fn new(kæde: &BløckKæde, previos_id: usize, content: BløckContent) -> Bløck {
        let cont_hæsh: [u8; 64] = content.hæsh_bløck();
        let prev_bløck_hæsh: [u8; 65] = kæde
            .bløcks
            .get(previos_id)
            .map(|x| x.hæsh.0)
            .unwrap_or([0; 65]);

        let mut buf = [0; 129];
        (&mut buf[0..64]).copy_from_slice(&cont_hæsh);
        (&mut buf[64..129]).copy_from_slice(&prev_bløck_hæsh);

        let bløck_hæsh: [u8; 64] = hæsh(&buf);

        let mut hæsh = [0; 65];
        (&mut hæsh[0..64]).copy_from_slice(&bløck_hæsh);

        // Extra verification byte
        let mut a = 0;
        for i in 0..64 {
            if hæsh[i] & 0xf0 == 0x60 {
                a = i as u8 * 2;
                break;
            }
            if hæsh[i] & 0x0f == 0x06 {
                a = i as u8 * 2 + 1;
                break;
            }
        }
        hæsh[64] = a;

        Bløck {
            content,
            previos_id,
            hæsh: ArrayU865(hæsh),
        }
    }
}

#[derive(Debug)]
pub enum BløckContent {
    CrætedAccøunt(AccøuntID, Passwørd),
    Transacksjon(AccøuntID, AccøuntID, f32), // from, to, amount
    Mine(AccøuntID),                          // miner
}

impl BløckContent {
    pub fn hæsh_bløck(&self) -> [u8; 64] {
        match self {
            BløckContent::CrætedAccøunt(AccøuntID(id), Passwørd(pass)) => {
                let mut buf = [0; 4 + 16];
                buf[3] = *id as u8;
                buf[2] = (id >> 8) as u8;
                buf[1] = (id >> 16) as u8;
                buf[0] = (id >> 24) as u8;

                for i in 0..16 {
                    buf[i + 4] = pass[i];
                }

                hæsh(&buf)
            }
            BløckContent::Transacksjon(AccøuntID(from), AccøuntID(to), amount) => {
                let amount_u32: u32 = unsafe { std::mem::transmute(*amount) };

                let mut buf = [0; 4 + 4 + 4];
                buf[3] = *from as u8;
                buf[2] = (from >> 8) as u8;
                buf[1] = (from >> 16) as u8;
                buf[0] = (from >> 24) as u8;

                buf[4 + 3] = *to as u8;
                buf[4 + 2] = (to >> 8) as u8;
                buf[4 + 1] = (to >> 16) as u8;
                buf[4 + 0] = (to >> 24) as u8;

                buf[8 + 3] = amount_u32 as u8;
                buf[8 + 2] = (amount_u32 >> 8) as u8;
                buf[8 + 1] = (amount_u32 >> 16) as u8;
                buf[8 + 0] = (amount_u32 >> 24) as u8;

                hæsh(&buf)
            }
            BløckContent::Mine(AccøuntID(id)) => {
                let mut buf = [0; 4];
                buf[3] = *id as u8;
                buf[2] = (id >> 8) as u8;
                buf[1] = (id >> 16) as u8;
                buf[0] = (id >> 24) as u8;

                hæsh(&buf)
            }
        }
    }
}
