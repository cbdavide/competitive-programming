#include <bits/stdc++.h>
using namespace std;

int f(string &word, int l, int e) {
    string temp = word.substr(l, e - l);
    int i=l, cont = 0;
    while(i < word.size()) {
        i = word.find(temp, i);
        if(i == string::npos) break;
        cont++; i += temp.size();
    }
    return word.size() - (temp.size() * cont) + temp.size() + cont;
}

int main() {
    string line;
    while(cin >> line) {
        int mini = line.size();
        for(int i=0; i<line.size(); i++) {
            for(int j=i+1; j<line.size(); j++)
                mini = min(f(line, i, j), mini);
        }
        cout << mini << '\n';
    }
    return 0;
}
