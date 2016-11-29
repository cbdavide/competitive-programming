
number = int(input())
answ = []

while(number != 0):
    answ.append(number % 2)
    number //= 2

i = 0
decimal = 0

for digit in answ[::-1]:
    decimal += digit * (2 ** i)
    i += 1

print(decimal)
