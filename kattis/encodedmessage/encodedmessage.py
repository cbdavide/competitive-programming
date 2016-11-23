from sys import stdin
import math

lines = stdin.read().splitlines()

t = int(lines.pop(0))

for i in range(0, t):
    word = lines[i]
    matrix = []
    size = int(math.sqrt(len(word)))

    contador = 0
    for j in range(0, size):
        matrix.append([])
        for k in range(0, size):
            matrix[j].append(word[contador])
            contador += 1

    for j in range(size - 1, -1, -1):
        for k in range(0, size):
            print(matrix[k][j], end = "")
        print(end = "")
    print()
