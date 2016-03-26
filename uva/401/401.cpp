#include <bits/stdc++.h>
using namespace std;

char espejos[35][2] = {
    'A', 'A',
    'E', '3',
    'H', 'H',
    'I', 'I',
    'J', 'L',
    'L', 'J',
    'M', 'M',
    'O', 'O',
    'S', '2',
    'T', 'T',
    'U', 'U',
    'V', 'V',
    'W', 'W',
    'X', 'X',
    'Y', 'Y',
    'Z', '5',
    '1', '1',
    '2', 'S',
    '3', 'E',
    '5', 'Z',
    '8', '8',
    '!', '!'
 };
 
 bool esEspejo(string word) {
    for(int i=0, j=(word.size()-1); (i<word.size() && j >= 0); i++, j--) {
       int k = 0;
       
       for(;(k<35 && word[i] != espejos[k][0]); k++) {}
       
       if(espejos[k][0] == '!')
        return false;
       
       if(word[j] != espejos[k][1])
           return false;
       
    }
    return true;
 } 

bool esPalindromo(string word) {
    for(int i=0, j=(word.size()-1); (i<word.size() && j >= 0); i++, j--) {
        if(word[i] != word[j])
            return false;
    }
    return true;
}

main() {
    
    string word, answer;
    
    while(cin >> word) {
        
        if(!esPalindromo(word) && !esEspejo(word)) {
           answer =  " -- is not a palindrome.";
        } else if(esPalindromo(word) && !esEspejo(word)) {
           answer =  " -- is a regular palindrome.";            
        } else if(!esPalindromo(word) && esEspejo(word)) {
           answer =  " -- is a mirrored string.";                        
        } else {
           answer =  " -- is a mirrored palindrome.";                                    
        }
        cout << word << answer << '\n' << '\n';
    }
    
}