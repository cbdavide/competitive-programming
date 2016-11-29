import math

def digitSum(num):
    strNum = str(num)
    total = 0

    for digit in strNum:
        total += int(digit)

    return total

def listDivisors(n):
    answ = []
    lim = int(math.sqrt(n))

    for i in range(1, lim + 1):
        if n % i == 0:
            answ.append(i)

            if n != lim:
                answ.append(n // i)

    answ.sort()
    return answ

number = int(input())

divisors = listDivisors(number)
digits = [digitSum(x) for x in divisors]

maxDigitSum = max(digits)
index = digits.index(maxDigitSum)

print(divisors[index])
