#include <bits/stdc++.h>
using namespace std;

main() {

    int nRules, begin;
    string search, replace, word;

    vector<string> toSearch;
    vector<string> toReplace;
    //Iterators
    vector<string>::iterator j;
    vector<string>::iterator k;

    while(cin >> nRules && nRules != 0) {
        getline(cin, word);
        for(int i=0; i<nRules; i++) {
            getline(cin, search);
            getline(cin, replace);

            toSearch.push_back(search);
            toReplace.push_back(replace);
        }
        getline(cin, word);

        for(j=toSearch.begin(), k=toReplace.begin(); j!=toSearch.end(); j++, k++) {
            begin = word.find((*j));
            
            while(begin != string::npos) {
                if((*k) == "") {
                    word.erase(begin, (*j).size());
                } else {
                    word = word.replace(begin, (*j).size(), *k);
                }
                begin = word.find((*j));
            }
        }
        cout << word << '\n';
        toSearch.clear();
        toReplace.clear();
    }
}
