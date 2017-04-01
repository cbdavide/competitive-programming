from sys import stdin
import math
lines = stdin.read().splitlines()

factorial = {}

factorial[0] = 1
factorial[1] = 1

divisors = {}

def d(n):
    if(divisors.get(n)):
        return d[n]

    cont = 0
    lim = math.ceil(math.sqrt(n))
    for i in range(1, lim):
        if n % i == 0:
            cont += 1

            if i != lim:
                cont += 1
    divisors[n] = cont
    return cont

def facti(n):
    if factorial.get(n):
        return factorial[n]
    factorial[n] = n * facti(n - 1)
    return factorial[n]

def generate(n, m):
    cont = 1;
    for i in range(n, m, -1):
        cont *= i
    return cont

for line in lines:
    n, m = [int(x) for x in line.split()]
    deno = min([m, (n - m)])
    num = generate(n , max([m , n - m]))
    answ = num // facti(deno)
    print(d(answ))
