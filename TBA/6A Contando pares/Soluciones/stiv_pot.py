"""
Contando pares ST 4
3^n - 2^n
frankr@coj
"""

MOD = 10 ** 9 + 7

n = input()

res = pow(3, n, MOD) - pow(2, n, MOD)

res += MOD
res %= MOD

print res
