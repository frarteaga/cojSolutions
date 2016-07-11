#1405 - Cutting Circles
#frankr@coj

s = [0, 1, 2, 4]
for _ in xrange(input()):
	n = input()
	if n < 4:
		print s[n]
	else:
		print (n - 3) * (n - 2) * (n - 1) * n / 24 + (n - 1) * (n - 2) / 2 + n

