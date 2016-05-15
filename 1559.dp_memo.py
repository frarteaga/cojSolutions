"""
1559 - Counting Scores
frankr@coj
"""

#from memoize import memoize

import functools

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

N = M = K = 0

@memoize
def f(i, S):
	if i == 1:
		return min(K, S) + 1
	r = 0
	for j in xrange(min(K, S) + 1):
		r += f(i - 1, S - j)
		r %= 10 ** 6
	return r

while True:
	N, M, K = [int(x) for x in raw_input().split()]
	if N == 0:
		break
	sol = f(N - 1, M - K)
	print sol
