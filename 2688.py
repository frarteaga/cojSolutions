uno = set()
dos = set()

lu = raw_input().split()
nu = lu[1]
cu = int(lu[2])

if cu != 0:
	uno = set([int(x) for x in raw_input().split()])

ld = raw_input().split()
nd = ld[1]
cd = int(ld[2])

if cd != 0:
	dos = set([int(x) for x in raw_input().split()])

def f(s):
	r = [x for x in s]
	r.sort()
	return str(r).replace('[', '{').replace(']', '}').replace(' ', '')

print nu + " U " + nd + ": " + f(uno.union(dos))
print nu + " I " + nd + ": " + f(uno.intersection(dos))
print nu + " D " + nd + ": " + f(uno.difference(dos))
print nd + " D " + nu + ": " + f(dos.difference(uno))

