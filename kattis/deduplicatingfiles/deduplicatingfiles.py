def hash(line):
    h = 0
    for letter in line:
        h ^= ord(letter)

    return h

def process(array):
    collisions = 0
    unrepeated = len(set(array))
    for i in range(len(array)):
        for j in range(i + 1, len(array)):
            if array[i] != array[j]:
                collisions += 1

    return unrepeated, collisions

num = int(input())
while num:
    hashtable = {}
    for i in range(num):
        line = input()
        h = hash(line)

        if not h in hashtable:
            hashtable[h] = []

        hashtable[h].append(line)

    collisions, singleFiles = 0, 0
    for k in hashtable.keys():
        a, b = process(hashtable[k])
        # print('>', k, a, b)
        singleFiles += a
        collisions += b

    print(singleFiles, collisions)
    # print('*' * 20)
    num = int(input())
