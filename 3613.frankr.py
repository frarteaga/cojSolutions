"""
3613 - Another GCD problem

Lema 1: Si gcd(a, b) = 1 entonces gcd(a + b, ab) = 1.
Lema 2: Si c | ab y c | ad y gcd(b, d) = 1 entonces c | a.

Ahora, MD evidentemente divide a MI.
Falta probar que MI divide a MD, lo cual después de 
dividir por d = gcd(a, b), sustituir a = d * m, b = d * n, aplicar los dos
lemas anteriores y queda demostrado.
"""
#frankr@coj

T = int(raw_input())


while T > 0:
	A = raw_input()
	B = raw_input()
	res = ''
	n = max(len(A), len(B))
	A += '0' * (n - len(A))
	B += '0' * (n - len(B))
	for i in xrange(n):
		if (A[i] == '1') and (B[i] == '1'):
			res += '1'
		else:
			res += '0'
	if res.find('1') == -1:
		print "relatively prime"
	else:
		print res[ : res.rfind('1') + 1]
	T -= 1
