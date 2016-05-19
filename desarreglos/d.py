"""
2587
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

@memoize
def d(n):
	if n < 4:
		return n - 1
	return (n - 1) * (d(n - 1) + d(n - 2)) % 1000000007

sol = 0
n = input()
for i in xrange(n + 1):
	sol = d(i)

print sol
	
