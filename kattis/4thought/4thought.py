
operators = ['+', '-', '*', '//']

operations = {}

for i in operators:
    for j in operators:
        for k in operators:
            statement = '4 {} 4 {} 4 {} 4'.format(i, j, k)
            result = eval(statement)

            operations[result] = i, j, k

t = int(input())
for i in range(t):
    n = int(input())

    if n > 256  or not n in operations:
        print('no solution')
    else:
        o1, o2, o3 = [x if x != '//' else '/' for x in operations[n]]
        print('4 {} 4 {} 4 {} 4 = {}'.format(o1, o2, o3, n))
