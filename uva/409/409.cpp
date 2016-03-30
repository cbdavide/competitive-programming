#include <bits/stdc++.h>
using namespace std;

string toLower(string s) {
    string answ;
    for(int i=0; i<s.size(); i++) {
        answ += tolower(s[i]);
    }
    return answ;
}

main() {

    int nWords, nExcuses, k=1, max;
    string aux, word;

    while(cin >> nWords >> nExcuses) {
        getline(cin, aux);
        map<string, int> excuses;
        vector<string> sentences;
        vector<int> ocurrences;

        for(int i=0; i<nWords; i++) {//Reading the excuses
            getline(cin, aux);
            excuses[toLower(aux)] = 1;
        }

        for(int i=0; i<nExcuses; i++) {//Reading the sentences
            getline(cin, aux);
            sentences.push_back(aux);
            ocurrences.push_back(0);
        }

        for(int i=0; i<sentences.size(); i++) {
            word = "";
            for(int j=0; j<sentences[i].size(); j++) {
                if(isalpha(sentences[i][j])) {
                    word += sentences[i][j];
                } else {
                    if(word != "") {
                        ocurrences[i] += excuses[toLower(word)];
                    }
                    word = "";
                }
            }
        }
        max = *max_element(ocurrences.begin(), ocurrences.end());
        cout << "Excuse Set #" << k << '\n';
        for(int i=0; i<sentences.size(); i++) {
            if(ocurrences[i] == max) {
                cout << sentences[i] << '\n';
            }
        }
        cout << '\n';
        k++;
    }
}
