#include <bits/stdc++.h>
using namespace std;

main() {
    string c, word;
    map<string, int> dictionary;
    
    while(cin >> c) {
        word = "";
        for(int i=0; i<c.size(); i++) {
            if(isalpha(c[i])) {
                word += tolower(c[i]);
            } else {
                if(word != "") {
                    if(dictionary[word] == 0) {
                        dictionary[word] = 1;
                    }
                    word = "";
                }
            }
        }
        if(word != "") {
            if(dictionary[word] == 0) {
                dictionary[word] = 1;
             }
             word = "";
        }
    }
    
    map<string, int>::iterator i;
    for(i = dictionary.begin(); i != dictionary.end(); i++) {
        cout << (*i).first << '\n';
    }
         
}