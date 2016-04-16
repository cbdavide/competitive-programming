#include <bits/stdc++.h>
using namespace std;

void to_lower(string& word) {
    for(int i=0; i<word.size(); i++) {
        word[i] = tolower(word[i]);
    }
}

main() {
    vector<string> words, wwords;
    map<string, int> answ;
    string temp;

    while(cin >> temp && temp != "#")
        words.push_back(temp);

    sort(words.begin(), words.end());
    for(int i=0; i<words.size(); i++) {
        temp = words[i];
        to_lower(temp);
        sort(temp.begin(), temp.end());
        answ[temp]++;
        wwords.push_back(temp);
    }

    for(int i=0; i<words.size(); i++) {
        if(answ[wwords[i]] == 1)
            cout << words[i] << endl;
    }
}
