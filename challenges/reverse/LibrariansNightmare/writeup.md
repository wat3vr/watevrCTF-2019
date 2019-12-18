# Librarians Nightmare

Looking at the source on the website, we can find the function to turn an index of a word into
a number, representing the word, as well as the function to covert the number to the actual
string.

We will start by looking at the function to covert a number to a string:

```python
chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789{}_'

[...]

def n2st(n, length = 7):
    if length == 0:
        return ""
    ch = chars[n % len(chars)]
    return n2st(n // len(chars), length - 1) + ch
```

This simply converts `n` into base 65, where the symbols are in ascending order in the constant
`chars`. We can easily write an inverse to this, `st2n`, converting a string back into a number.


Next up, the function making index to numeber goes as follows:

```python
def f(n):
    if n == 0:
        return (c + k) % m
    if n % 2 == 0:
        fx = f(n // 2)
        return (k + (fx ** 2 - 2 * k * fx + k ** 2) * d) % m
    else:
        fx = f((n - 1) // 2)
        return (k + a * (fx ** 2 - 2 * k * fx + k ** 2) * d) % m
```

(source/backend.py:13-21)

The value of `c`, `a`, `k` and `d` are unknown, but we know from the `assert` at line 5, that
`c * d = 1 (mod m)`, which means that `c` and `d` are multiplicative inverses of one another.

The function is written in a recursive way, but we can see that the function is exactly the
same as `f(n) = k + c * a ^ x` (where `^` is exponentiation).

We have three unknown values in this equation. By looking at the three first words in the book,
which have `n = 0, 1, 2`, we can convert these words back into numbers and solve for `c`, `a`
and `k`. Using the extended euclidian algorithm, we can find the value of `d` as well.

Now that we know exactly what the function is, we need to solve for where
`f(n) = st2n('watevr{')`. Plugging in `f`, we have

```
    k + c * a ^ n = st2n('watevr{') <=>
<=> c * a ^ n = st2n('watevr{') - k <=>
<=> d * c * a ^ n = d * st2n('watevr{) - d * k <=>
<=> a ^ n = d * st2n('watevr{') - d * k
```

To find a value `n`, such that `a ^ n` is some given value, we need to use the discrete
logarithm, `n = log_a (d * st2n('watevr{') - d * k)`. An implementation of it can be
found on [WikiPedia](https://en.wikipedia.org/wiki/Baby-step_giant-step), or copied from
[StackOverflow](https://stackoverflow.com/a/37237257/1753929). In general, finding the
discrete logarithm is a hard problem, but as `m` is not too big this runs in a few seconds.

Once we know the value of `n`, we go to the page `n // 100`, as there are 100 words on each
page. There we will find the string `watevr{`, followed by the rest of the flag.

