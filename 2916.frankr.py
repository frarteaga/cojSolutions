import sys
import fractions

for s in sys.stdin:
    a,b = map(int, s.split())
    if(fractions.gcd(a, b) == 1):
        print "YES"
    else:
        print "NO"
