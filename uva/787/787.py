from sys import stdin

lines = stdin.read().splitlines()

for line in lines:
	A = [int(x) for x in line.split()[:-1]]

	maxG, maxC, minC = A[0], A[0], A[0]

	for num in A[1: ]:
		temp = maxC
		maxC = max([num, temp * num, minC * num])
		minC = min([num, temp * num, minC * num])
		maxG = max([maxG, maxC, minC])

	print(maxG)