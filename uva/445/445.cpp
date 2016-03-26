#include <bits/stdc++.h>
using namespace std;

bool isNumber(char c) {
    return (c >= '1' && c <= '9');
}
bool isLetter(char c) {
    return ((c >= 'A' && c <= 'Z') || c == '*');
}
bool isSpace(char c) {
    return c == 'b';
}

bool isNewLine(char c) {
    return (c == '!' || c == '\n');
}

main() {
    
    char caracter;
    
    int nTimes = 0;
    while(cin.get(caracter)) {

        if(isNumber(caracter)) {
            nTimes += caracter - 48;   
        }
        
        else if(isLetter(caracter) || isSpace(caracter)) {
            
            if(isSpace(caracter))
                caracter = ' ';
            
            for(int i=0; i<nTimes; i++)
                cout << caracter;
                
            nTimes = 0;
        }
        
        else if(isNewLine(caracter)) {
            cout << '\n';
            nTimes = 0;
        }        
    }
}