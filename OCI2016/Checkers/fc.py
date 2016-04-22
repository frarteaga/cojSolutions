import sys

def main():
	l1 = open(sys.argv[1], 'r').readlines()
	l2 = open(sys.argv[2], 'r').readlines()

	if l1[-1][-1] == '\n':
		l1[-1] = l1[-1][: -1]
		
	if l2[-1][-1] == '\n':
		l2[-1] = l2[-1][: -1]

	import string

	#print string.join(l1, '\n'), string.join(l2, '\n')
	if string.join(l1, '\n') == string.join(l2, '\n'):
		sys.exit(0)
	else:
		sys.exit(1)

if __name__ == '__main__':
	main()
	


