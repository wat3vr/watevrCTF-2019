# Punk Whine

If we run the script `punk_whine.pl` after installing the required libraries, we can see that the script
prints itself, with a few modifications. Firstly, the value of `$n` is changed completely, lastly, the
value of `$i` decreases by one. If we run the output, the pattern continues. `$n` is changed, `$i` is
decreased.

We can see that on line 10, the code is as follows:

```perl
exit [expression contaiing print] if $i;
```

If we set `$i` to zero directly in the script, we can see that it prints a bunch of garbage. This is
because `$i` is not true, meaning the `exit` was not run, and the next line was run instead.

If we examine this line carefully, we can see that it converts `$n` to ascii, and prints each char
until a byte with value under 32 is reached.

We also want to know exactly what happens with `$n` at each iteration. This can be found on line 9,
which says that `$n` is updated with the value `($n ^ ($n << 1)) % 2 ** 16` (`^` means XOR).

Lastly, the only way the script prints something other than itself modified, is when `$i` is 0. The
only way for `$i` to become 0 is to run the script 275707953942 times. However, this is not really
feasible.

If we make a program to do this automatically, we can see that the value of `$n` repeats every
`2 ** 16`'th iteration. This means that we can simply set `$i` to `$i % 2 ** 16` and it will give
the same result. Doing `2 ** 16 = 65536` iterations in a program is very quick, and gives us the value
of `$n` when `$i` has reached 0. Putting the value of `$n` into the script and setting `$i = 0` gives
the flag.

This can also be solved without knowing that `$n` repeats. First we can see that if `a ^ b == n`, then
`(a ^ (a << 1)) ^ (b ^ (b << 1)) == n ^ (n << 1)` because:

```
   (a ^ (a << 1)) ^ (b ^ (b << 1)) ==
== (a ^ b) ^ ((a << 1) ^ (b << 1)) ==
== (a ^ b) ^ ((a ^ b) << 1) ==
== n ^ (n << 1)
```

This means that we can consider each bit of `$n` on it's own, doing the operation on it the specified
number of times, and then XORing together all the results.

If we iterate over one bit, we can easily see that this generates
[Pascal's Triangle](https://en.wikipedia.org/wiki/Pascal%27s_triangle), modulus 2 in binary.

More specifically, if we start with a single 1, and repeat the formula `n |-> n ^ (n - 1)` `m` times,
we will find that the value of bit `i` is the value of Pascal's Triangle on row `m`, column `i` from
the left (modulu 2). It's well known that this value is simply `m choose i (mod 2)`. If we don't start
with a one, but some other power of 2, the triangle will just be shifted to the left.

This means that if we can find the value of a position in Pascal's Triangle modulu 2 quickly, we can
find the result for each bit's final iteration.

By [Lucas's Theorem](https://en.wikipedia.org/wiki/Lucas%27s_theorem) with `p = 2`, we find that if
`m` is composed of bits `m_a, m_(a-1), ..., m_1, m_0`, and `i` is composed of bits
`i_a, i_(a-1), ..., i_1, i_0`, the value of `m choose i (mod 2)` is simply the product of
`m_b choose i_b` for all `0 <= b <= a`.

As all `m_b` and `i_b` are either zero or one, the only values of `m_b choose i_b` is also either zero
or one. The only way it's zero is when `m_b == 0` and `i_b == 1` which is equivalent to saying that if
there is any `b` such thath `~m_b == 1` and `i_b == 1`, which is the same as `~m_b & i_b == 1`, then
the whole product is zero.

This can be computed bitwise. If `~m & i == 0` then `m choose i = 1 (mod 2)`.

On each bit in `n`, we will check if it's one, and if so, XOR the result with the value of Pascal's
Tringale's `i`th row shifted to the left, matching the bit.

This means that we can implement everything as follows:

```python

def pascal_mod_2(m, i):
    return ~m & i == 0

n = <$n from the script>
i = <$i from the script>

pascal_row_i = 0
for m in range(2 ** 16):
    if pascal_mod_2(i, m):
        pascal_row_i |= 1 << m

result = 0

res_mask = 2 ** (2 ** 16) - 1

for bit_idx in range(2 ** 16):
    if n & (1 << bit_idx):
        # The bit is on, we'll take it into account
        result ^= res_mask & (pascal_row_i << bit_idx)

```

We now have the resulting value of `$n` after `$i` iterations, without needing to know that it cycles.
Simply convert it to ascii and strip at the first byte less than 32 and you have the flag!
