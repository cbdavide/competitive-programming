from sys import stdin

lines = stdin.read().splitlines()

def factorial(n):
    if n == 1:
        return 1
    else :
        return  n * factorial(n-1);

for line in lines:
    chars = {}
    numerator = 0
    denominator = 1

    for char in line:
        chars[char] = 0;

    for char in line:
        chars[char] = chars[char] + 1;

    numerator = factorial(len(line))

    for keys, value in chars.items():
        if value > 1:
            denominator = denominator * factorial(value)

    print(numerator // denominator)
