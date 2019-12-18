# M-x 5x5

We can start by examining the given executable, and seeing that the `sym.flip` function is something
like the following:

```c
void flip(char* board, int position, int size) {
  int x = position & 0xf;
  int y = position >> 4;
  if (y > 0) {
    board[y - 1] ^= 1 << x;
  }
  int mask = 0b11;
  if (x > 0) {
    mask = 0b111 << (x - 1);
  }
  board[y] ^= mask;
  if (y < 15) {
    board[y + 1] ^= 1 << x;
  }
}
```

For 8x8 Lights out, we can turn any position into any other position (the proof and method for
doing this, while not trivial, is left as an exercise to the reader). This also means that we
can take any position XOR anything, even if we do not what position it is.

Here we can see that we can write as normally four bytes outside of the buffer, which we can see
is the register `$rbp`, stored on the stack for the return to `main`. In `main`, there is a `char`
pointer, which initially points to the text `"Bye!"`, and will be changed to `"Good job, you won!"`
if the `play_game` function returns a one, which it never will. This pointer is stored in `$rbp-0x8`
in `main`. What we can do is to change the `$rbp` stored on the stack, which in turn makes `$rbp-0x8`
point to any location we want.

For our expoit, we will make `$rbp-0x8` point to the board, which is `$rbp-0x8` in the `play_game`
function. Dynamic analysis can show us that the difference between `$rbp` in `main` and `play_game` is
exactly `0x20`. As we don't know the value of `$rbp` at any point, due to ASLR in the server, we will
either have to guess it, or try every possibility. We know that `$rbp` is aligned to 8 bytes, as
it would cause a segfault otherwise. Brute forcing, we can see that we need to XOR by `0x20`, `0x60`,
`0xe0` or `0x1e0` to subtract by `0x20`, depending on the value of `$rbp`. Once we've XOR:ed `$rbp`
with the correct value, we only need to change the board to be a pointer to the flag string, which is
trivial.

Now we only need to guess what the value of `$rbp` is, and use the corresponding XOR. This should take
around 4 attempts, and then the service should print the flag for us.