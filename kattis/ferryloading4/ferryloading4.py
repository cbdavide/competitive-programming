from sys import stdin

def extract(arr, v):
    carry = 0

    while arr and (carry + arr[0]) <= v:
        carry += arr.pop(0)

lines = stdin.read().splitlines()

t = int(lines.pop(0))

for k in range(0, t):
    left = []
    right = []
    carry = 0
    times = 0

    l, c = lines.pop(0).split(' ')
    l = int(l)

    for i in range(0, int(c)):
        size, orientation = lines.pop(0).split(' ')

        if orientation == 'left':
            left.append(int(size) / 100)
        else :
            right.append(int(size) / 100)

    while left or right:

        if left:
            extract(left, l)
            times += 1
        else:
            times += 1

        if not left and not right:
            break

        if right:
            extract(right, l)
            times += 1
        else:
            times += 1

    print(times)
