#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i'
        || c == 'o' || c == 'u' || c == 'y';
}

string transform(string word) {
    while(!is_vowel(word[0])) {
        word.push_back(word[0]);
        word.erase(word.begin());
    }
    return word;
}

int main() {
    string line, word;
    while(getline(cin, line)) {
        stringstream ss(line);
        vector<string> vs;
        while(ss >> word) {
            if(is_vowel(word[0])){
                vs.push_back(word + "yay");
            }else {
                vs.push_back(transform(word) + "ay");
            }
        }

        for(int i=0; i<vs.size(); i++) {
            cout << vs[i];
            if(i < vs.size() - 1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
