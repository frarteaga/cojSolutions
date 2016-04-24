/*
Given a positive integer n, find the number of pairs (i, j) in the set {0, 1, 2, ... 2^n - 1}, such that j > i and j & i == i.

Example

For n = 2, the output should be
countPairs(n) = "5".

The valid pairs are: (0, 1), (0, 2), (0, 3), (1, 3) and (2, 3).

    [input] integer n

	    1 ≤ n ≤ 30.

    [output] string

	    String representation of the number of pairs.

autor: https://codefights.com/profile/vswamy
*/

def f(n):
    r = 1
    for i in xrange(2, n + 1):
        r *= i
    return r

def c(n, k):
    return f(n) / f(k) / f(n - k)

def countPairs(n):
    r = 0
    for k in xrange(n):
        r += c(n, k) * (2 ** (n - k) - 1)
    return str(r)

