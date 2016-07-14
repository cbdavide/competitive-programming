#include<bits/stdc++.h>
using namespace std;

int main() {
    string line, code;
    int sCode, pos;

    cin >> line >> code;

    sCode = code.size();
    pos = line.find(code);
    
    while(pos != string::npos) {
        line.replace(pos, sCode, "");
        pos = line.find(code);
    }

    if(line == "")
        cout << "FRULA\n";
    else
        cout << line << endl;

    return 0;
}