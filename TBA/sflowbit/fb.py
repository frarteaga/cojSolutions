def o(n):
	r = 0
	for d in bin(n):
		if d == '1':
			r += 1
	return r

def sfl(n):
	return n * (n + 1) / 2 - sum(o(i) for i in xrange(1, n + 1))

n = input()
print sfl(n)
