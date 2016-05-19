"""
3369 - Army
frankr@coj
"""

MOD = 1000000007

def invMod(a):
	return pow(a, MOD - 2, MOD)

N, K = [int(x) for x in raw_input().split()]

d = [0] * (N - K + 2)

d[1] = 0
d[2] = 1
for i in xrange(3, N - K + 1):
	d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % MOD

f = [0] * (N + 1)

f[0] = 1
for i in xrange(1, N + 1):
	f[i] = f[i - 1] * i % MOD

sol = d[N - K] * f[N] * invMod(f[K]) * invMod(f[N - K]) % MOD

print sol
