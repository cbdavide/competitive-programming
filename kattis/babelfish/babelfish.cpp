#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string line, en, babel, temp;
    int space;
    map<string, string> dic;

    while(getline(cin, line) && line != ""){
        space = line.find(' ');
        en = line.substr(0, space);
        babel = line.substr(space + 1);
        dic[babel] = en;
    }

    while(cin >> line) {
        temp = dic[line];
        if(temp != "")
            cout << temp << '\n';
        else
            cout << "eh\n";
    }

    return 0;
}
