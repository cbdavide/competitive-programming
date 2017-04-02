#Generate all the valid values
def check(n, a = 0):
    for i in range(a, 10**n):
        p1 = i // (10**(n//2))
        p2 = i % (10**(n//2))
        if((p1 + p2)**2 == i):
            print(i)

print("> 2:")
check(2)
print("> 4:")
check(4)
print("> 6:")
check(6)
print("> 8:")
check(8)
