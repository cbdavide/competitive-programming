#include <bits/stdc++.h>
using namespace std;

main() {
    map<string, int> dicctionary;
    int nWords, nC, value, result;
    string word;
    cin >> nWords >> nC;

    for(int i=0; i<nWords; i++) {
        cin >> word >> value;
        dicctionary[word] = value;
    }

    for(int i=0; i<nC; i++) {
        word = "";
        result = 0;
        while(word != ".") {
            cin >> word;
            result += dicctionary[word];
        }
        cout << result << '\n';
    }
}
