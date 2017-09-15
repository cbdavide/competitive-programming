def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

n = int(input())
for i in range(n):
    x, y = [int(z) for z in input().split('/')]
    print(x // gcd(x, y), '/', y // gcd(x, y))
