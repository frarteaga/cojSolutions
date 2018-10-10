import sys
raw_input = lambda:sys.stdin.readline().rstrip()
input = lambda:int(raw_input())

Q = input()

N = 10 ** 6 + 1
BIT = [0] * N


def update(i, v):
    while i < N:
        BIT[i] += v
        i += i & -i


def query(i):
    r = 0
    while i > 0:
        r += BIT[i]
        i -= i & -i
    return r


while Q > 0:
    L = raw_input().split()
    if len(L) == 2:
        x = int(L[1])
        update(x, 1)
    else:
        a = int(L[1])
        b = int(L[2])
        res = query(b) - query(a - 1)
        print res
    Q -= 1
