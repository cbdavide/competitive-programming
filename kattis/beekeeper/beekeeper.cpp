#include <bits/stdc++.h>
using namespace std;
bool vowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i') return true;
    if(c == 'o' || c == 'u' || c == 'y') return true;
    return false;
}
int main() {
    int n, maxi, par;
    string word, aux;
    while(cin >> n && n) {
        maxi = -1;
        while(n--) {
            par = 0;
            cin >> word;
            for(int i=0; i<(int)word.size()-1; i++) {
                if(vowel(word[i]) && word[i] == word[i + 1]) {
                    par++; i++;
                }
            }
            if(par > maxi) {
                maxi = par;
                aux = word;
            }
        }
        cout << aux << '\n';
    }
}
