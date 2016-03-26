from sys import stdin

lines = stdin.read().splitlines()

maxLength = 0
for line in lines:
    if len(line) > maxLength:
        maxLength = len(line)
        
for j in range(0, maxLength):
    string = ''
    for i in range(len(lines)-1, -1, -1):
        if(len(lines[i]) > j):
            string += lines[i][j]
        else:
            string += ' '
    print(string)