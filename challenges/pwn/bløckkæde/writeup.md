# Danish Blockchain

At first, we can see that mining for coins will not give enough for a flag. The initial mining amount is
set such that the maximum amount of coins that can be mined is 20, while the amount needed for a flag is
32. (kæde.rs:5-9)

We continue by noting that the `hæsh` property of a Block is 64 bytes of hash and one verification byte,
as noted in kæde.rs:127-132. The "verification byte" is simply the index of the last number 6 in the hex
expansion of the hash. However, if there is no 6 in the hash, the verification byte will be set to 0. In
this case, the code considers that block invalid.

In the function `BløckKæde::get_account_money`, we can see that there is a difference between the
verification byte checking mechanism in a transaction *from* the user and *to* the user. The transaction
from the user works as expected, where an invalid verification makes the transaction fail. However, in
the transaction to the user, the verification always succeeds, as the varialbe `good` is reused from the
check for the user's existance.

This means that if we can force a transaction block to have an invalid verification byte, the
transaction will give the receiving account the specified amount of money, without drawing it from the
sender.

The solution is to first mine enough money for half the flag, then create another user, and doing a
transaction of all the money from the first account to this account. However, the user password for the second
account needs to be set in such a way that the hash of the transaction block has no 6's in it. This can
be brute forced locally, as there is a (1-1/16)^128 ≈ 1/4000 chance of it happening, which means that we will only have to
search around 4000 user passwords. When the transaction succeeds without drawing any money from the first
account, we can simply make a transaction, moving the money back to the first account, effectively
doubling it's money, which means we have enough money to buy the flag.

Practically, we start by creating a first user, 0x123, with a password of "xyz". We then log in to this
account, mine five times, giving us a balance of about 15.6 coins. If we now create a user with id 0,
password 'ED' and transfer 15 coins to that account, we will still have our ~15.5 coins left on our first
account. Transfer the 15 back, and we have 30.6 coins on our account, enough to buy us a flag!
