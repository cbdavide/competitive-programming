from sys import stdin
from functools import reduce

nImages = int(input(''))

while nImages != 0 :
    results = []
    totalSpaces = 0
    for n in range(0, nImages):
        cont = 0
        line = input('')
        
        for i in range(0, 25):            
            if line[i].isspace():
                cont += 1
        results.append(cont)
    
    minVal = min(results)
    for nSpaces in results:
        totalSpaces += nSpaces - minVal
    print(totalSpaces)
    nImages = int(input('')) 

