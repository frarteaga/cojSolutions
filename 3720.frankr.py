#3720 - Count the Trees
#Catalan(N) * factorial(N)
#frankr@coj

import math

f = math.factorial

def C(N, K):
	return f(N) / f(K) / f(N - K)

def ca(N):
	return C(N + N, N) / (N + 1)

while 1:
	N = int(raw_input())
	if N == 0:
		break
	S = ca(N) * f(N)
	print S	
