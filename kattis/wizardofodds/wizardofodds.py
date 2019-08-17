from math import log2
from math import ceil

n, k = [int(x) for x in input().split()]

if ceil(log2(n)) <= k:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")
