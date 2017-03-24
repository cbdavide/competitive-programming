from os import sys
sys.setrecursionlimit(10000)
c = {}

def catalan(n):
    if n in c:
        return c[n]
    c[n] = ((4 * n - 2) * catalan(n - 1) // (n + 1))
    return c[n]

def main():
    c[0] = 1
    c[1] = 1

    t = int(input())
    for i in range(t):
        a = int(input())
        print(catalan(a))

main()
