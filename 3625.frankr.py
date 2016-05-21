"""
3625 - Harry Potter and the Stones
Game Theory. Winner, loser positions
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
def f(x, c):
	if x == 1:
		return True
	if x == 0:
		return False
	for t in xrange(1, 2 * c + 1):
		if x - t < 0:
			break
		if not f(x - t, t):
			return True
	return False

#Para que no explote la recursividad
for N in xrange(300, 5001, 200):
	for c in xrange(1, N):
		f(N - c, c)

#Para deducir patroon:
"""
for N in xrange(1, 100):
	r = 'L'
	for c in xrange(1, N):
		if not f(N - c, c):
			r = 'W'
			break
	print r
"""	

Tests = input()

while Tests > 0:
	N = input()
	res = 'Harry'
	for c in xrange(1, N):
		if not f(N - c, c):
			res = 'Ron'
			break
	print res, 'wins'
	Tests -= 1

