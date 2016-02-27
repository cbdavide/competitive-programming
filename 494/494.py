from sys import stdin
lines = stdin.read().splitlines()
for line in lines:
    cond = False
    cont = 0
    for letter in line:
    
        if letter.isalpha():
        
            if(not cond):
                cont += 1
                cond = True
        else:
            cond = False
            
    print(cont) 