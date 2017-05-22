from os import sys
sys.setrecursionlimit(100000)
c = {}
f = {}

c[0] = 1
c[1] = 1

def catalan(n):
    if n in c: return c[n]
    c[n] = ((4 * n - 2) * catalan(n - 1) // (n + 1))
    return c[n]

def facto(n):
    if n == 0 or n == 1 : return 1
    if n in f: return f[n]
    f[n] = n * facto(n - 1)
    return f[n]

n = int(input())
while n != 0:
    print(facto(n) * catalan(n))
    n = int(input())
