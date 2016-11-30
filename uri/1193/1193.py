valid = {
    '0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5,
    '6': 6, '7': 7, '8': 8, '9': 9, 'a': 10, 'b': 11,
    'c': 12, 'd': 13, 'e': 14, 'f': 15
}

validOutput = {
    10: 'a', 11: 'b', 12: 'c', 13: 'd',
    14: 'e', 15: 'f'
}

def toDec(num, base):
    total = 0
    i = len(num) - 1

    for digit in num:
        total += valid[digit] * (base ** i)
        i -= 1

    return total

def fromDec(num, base):
    number = []
    num = int(num)

    while num != 0:
        number.append(num % base)
        num //= base

    number = [str(n) if n < 10 else validOutput[n] for n in number]
    number.reverse()
    return ''.join(number)


t = int(input())
for i in range(t):
    num, base = input().split()

    print('Case {}:'.format(i + 1))

    if base == 'bin':
        print('{} dec'.format(toDec(num, 2)))
        print('{} hex'.format(fromDec(toDec(num, 2), 16)))

    elif base == 'dec':
        print('{} hex'.format(fromDec(num, 16)))
        print('{} bin'.format(fromDec(num, 2)))

    elif base == 'hex':
        print('{} dec'.format(toDec(num, 16)))
        print('{} bin'.format(fromDec(toDec(num, 16), 2)))

    print()
