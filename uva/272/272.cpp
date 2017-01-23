#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    bool isOpen = false;

    while(getline(cin, line)) {
        for(int i=0; i<line.size(); i++) {
            if(line[i] == '"') {
                if(isOpen) {
                    line[i] = '\'';
                    line.insert(i, 1, '\'');
                    isOpen = false;
                } else {
                    line[i] = '`';
                    line.insert(i, 1, '`');
                    isOpen = true;
                }
            }
        }
        cout << line << '\n';
    }
    return 0;
}
