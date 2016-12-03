
def generate():
    return list('?'*32)

def resolveAND(i, j):
    if i == '?' and j == '?':
        return '?'

    if (i == '?' or j == '?') and (i == '0' or j == '0'):
        return '0'

    if (i == '?' or j == '?') and (i == '1' or j == '1'):
        return '?'

    b = bool(int(i)) and bool(int(j))
    return str(int(b))

def resolveOR(i, j):
    if i == '?' and j == '?':
        return '?'

    if (i == '?' or j == '?') and (i == '1' or j == '1'):
        return '1'

    if (i == '?' or j == '?') and (i == '0' or j == '0'):
        return '?'

    b = bool(int(i)) or bool(int(j))
    return str(int(b))


instructions = int(input())

while instructions != 0:
    bitset = generate()

    for k in range(instructions):
        op, *index = input().split()
        index = [int(x) for x in index]

        if op == 'CLEAR':
            bitset[index[0]] = '0'
        elif op == 'SET':
            bitset[index[0]] = '1'
        elif op == 'OR':
            bitset[index[0]] = resolveOR(bitset[index[0]], bitset[index[1]])
        else:
            bitset[index[0]] = resolveAND(bitset[index[0]], bitset[index[1]])

    bitset.reverse()

    print(''.join(bitset))

    instructions = int(input())
