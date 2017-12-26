import sys

def fact(n):
    if n==0:
        return 1
    else:
        return n*fact(n-1)

t = int(input())
for i in xrange(t):
    n = int(input())
    ans = fact(n)
    print ans
