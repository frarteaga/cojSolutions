while 1:
	try:
		s = raw_input()
		r = ''
		d = {}
		for c in s:
			if c not in d:
				Id = len(d) + 1
				d[c] = Id
			r += str(d[c])
		sol = ''
		for x in r:
			c = x
			if x == '2':
				c = '5'
			elif x == '5':
				c = '2'
			elif x == '6':
				c = '9'
			elif x == '9':
				c = '6'
			sol += c
		print sol
	except:
		break
