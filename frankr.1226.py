#By FR

import random

def gcd(a, b):
	while b != 0:
		r = a % b
		a = b
		b = r
	return a

def rho_try(n, a, c):
	x = 2
	y = 2
	d = 1
	while d == 1:
		x = (a * x * x + c) % n
		y = (a * y * y + c) % n
		y = (a * y * y + c) % n
		d = gcd(abs(x - y), n)
		if d == n:
			return None
	return d

"""
Selfridge and Wagstaff and Jaeschke have verified that
    * if n < 1,373,653, it is enough to test a = 2 and 3.
    * if n < 9,080,191, it is enough to test a = 31 and 73.
    * if n < 4,759,123,141, it is enough to test a = 2, 7, and 61.
    * if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11.
    * if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13.
    * if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
"""

def Miller_Rabin_pass(a, n):
	d = n - 1
	s = 0
	while d % 2 == 0:
		d >>= 1 # d /= 2
		s += 1
	x = pow(a, d, n) # a^d % n
	if x == 1 or x == n - 1:
		return True
	while s > 0:
		x = (x * x) % n
		if x == n - 1:
			return True
		s -= 1
	return False
	
def Miller_Rabin(L, n):
	for x in L:
		if not Miller_Rabin_pass(x, n):
			return False
	return True

#(2, 3, 5, 7, 11, 13, 17, 31, 61, 73, 23)

def factoriza(n):
	if n in (2, 3, 5, 7, 11, 13, 17, 31, 61, 73, 23) or Miller_Rabin((2, 3, 5, 7, 11, 13, 17, 31, 61, 73, 23), n) == True:
		return [n, ]
	d = rho_try(n, random.randint(1, 100), random.randint(3, 10000))
	while d == None:
		d = rho_try(n, random.randint(1, 100), random.randint(3, 10000))
	return factoriza(d) + factoriza(n / d)

s = ''
while 1:
    n = int(raw_input())
    if n == -1:
        break
    f = factoriza(n)
    f.sort()
    for x in f:
        s += (4 * ' ') + str(x) + '\n'
    s += '\n'
    
print s[ : -2]
