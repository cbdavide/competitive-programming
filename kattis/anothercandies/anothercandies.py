t = int(input())
for i in range(t):
    input()
    n = int(input())
    cont = 0

    for j in range(n):
        cont += int(input())

    if cont % n == 0:
        print("YES")
    else:
        print("NO")
