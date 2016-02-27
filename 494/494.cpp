#include <bits/stdc++.h>
using namespace std;
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
main() {
    char frase[1024];
    while(gets(frase)) {
     int i = 0, cont = 0;
     bool cond = false;
     while(frase[i] != '\0') {
         if(isLetter(frase[i])) {
             if(!cond) {
                cont ++;
                cond = true;                 
             }
         } else {
             cond = false;
         }
         i++;
     }
     cout << cont << endl;   
    }    
}