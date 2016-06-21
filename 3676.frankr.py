t = input()

for tt in xrange(1, t + 1):
	N = input()
	N *= 2
	SN = str(N)
	if SN[-1] != '0':
		SN = SN[: -1] + "," + SN[-1]
		if SN[0] == ",":
			SN = "0" + SN
	else:
		SN = SN[: -1]
	print "Case " + str(tt) + ": " + SN
	t -= 1
