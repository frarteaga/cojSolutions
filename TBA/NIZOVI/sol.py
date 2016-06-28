A = raw_input() + ' '

d = 0
f = 0

r = ''

for i in xrange(len(A) - 1):
	x = A[i]
	if x == '{':
		r += ('  ' * d) + '{\n'
		d += 1
		f = 1
	elif x == ',':
		r += x + '\n'
		f = 1
	elif x == '}':
		d -= 1
		r += ('  ' * d) + '}'
		if A[i + 1] == '}':
			r += '\n'
		f = 1
	else:
		if f:
			r += ('  ' * d) + x
		else:
			r += x
		f = 0
		if A[i + 1] == '}':
			r += '\n'

r = r.replace('\n\n', '\n').strip()
print r
