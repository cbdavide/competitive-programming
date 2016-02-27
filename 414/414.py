from sys import stdin
from functools import reduce

nImages = int(input(''))

while nImages != 0 :
    results = []
    
    for n in range(0, nImages):
        cont = 0
        line = input('')
        j = 1
        
        for char in line:            
            if char.isspace():
                cont += 1
            if(j == 25):
                break
            j += 1
        results.append(cont)
    
    minVal = min(results)
    results = list(map((lambda val: val - minVal), results))
    nSpaces = reduce((lambda x, y: x + y), results)
    print(nSpaces)
    nImages = int(input('')) 

