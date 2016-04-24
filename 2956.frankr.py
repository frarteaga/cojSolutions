#2956 - FITA World Cup
#Permutaciones con repeticiones
#frankr@coj

import math

fact = math.factorial

MOD = 10 ** 9 + 7

while 1:
	try:
		N, K = [int(x) for x in raw_input().split()]
		res = fact(N) / (fact(N / K) ** K) % MOD
		print res
	except:
		break
