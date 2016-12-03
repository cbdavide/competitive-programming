from sys import stdin
lines = stdin.read().splitlines()

def getOnes(num):
    binary = bin(int(num))
    cont = 0;

    for bit in binary[2:]:
        if bit == '1':
            cont += 1

    return cont

t, *case = lines

for i in range(int(t)):
    num = ''
    bits = []
    
    for digit in case[i]:
        num += digit
        bits.append(getOnes(num))

    print(max(bits))
