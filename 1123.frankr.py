"""
1123 - Ugly Numbers II
Busqueda binaria
frankr@coj
"""

primes = (2, 3, 5)

u = [0, 1]

for i in xrange(2, 1501):
	uk = u[-1] * 5
	for p in primes:
		ini = 1
		fin = len(u) - 1
		while fin - ini > 5:
			mit = (ini + fin) >> 1
			if u[mit] * p <= u[-1]:
				ini = mit + 1
			else:
				fin = mit
		while u[fin] * p > u[-1]:
			fin -= 1
		fin += 1
		if u[fin] * p < uk:
			uk = u[fin] * p
	u.append(uk)


while 1:
	n = int(raw_input())
	if n == 0:
		break
	print u[n]

