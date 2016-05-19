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

import math
fact = math.factorial

def fb(n):
	r = 0
	for i in xrange(n + 1):
		sig = -1
		if i % 2 == 0:
			sig = 1;
		r += sig * fact(n) / fact(i)
	return r

for i in xrange(1, 100):
	assert fb(i) % 1000000007 == d(i)

sol = 0
n = input()
for i in xrange(n + 1):
	sol = d(i)

print sol
	
