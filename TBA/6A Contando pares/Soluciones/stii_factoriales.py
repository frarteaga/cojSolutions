"""
Contando pares ST 2
sum(c(n, k) * (2^(n - k) - 1)) para k=0..n-1
frankr@coj
"""

MOD = 10 ** 9 + 7

import math

f = math.factorial #hasta 2000 los factoriales los calcula bastante rapido y caben bien en memoria

def c(n, k):
    return f(n) / f(k) / f(n - k) % MOD

def countPairs(n):
    r = 0
    for k in xrange(n):
        r += c(n, k) * (pow(2, n - k, MOD) - 1)
	r = (r + MOD) % MOD
    return r

n = input()

print countPairs(n)

