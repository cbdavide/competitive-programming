from sys import stdin

lines = stdin.read().splitlines()

for line in lines:
    exp = line.split()
    a = int(exp[0][-4: ])
    o = exp[1]
    b = int(exp[2][-4: ])

    if(o == '+'):
        r = a + b
    elif(o == '*'):
        r = a * b
    elif(o == '^'):
        r = a ** b

    answ = str(r)[-4: ]
    print(int(answ))
