#2956 - FITA World Cup
#Permutaciones con repeticiones
#frankr@coj

import math
import functools

fact = math.factorial

def memoize(function):
    cache = {}
    @functools.wraps(function)
    def memoized(*args):
        if args in cache:
            return cache[args]
        else:
            res = function(*args)
            cache[args] = res
            return res
    return memoized

MOD = 10 ** 9 + 7

@memoize
def f(x):
	return fact(x)

while 1:
	try:
		N, K = [int(x) for x in raw_input().split()]
		res = f(N) / (f(N / K) ** K) % MOD
		print res
	except:
		break
