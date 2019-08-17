#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> is;
typedef vector<is> vis;

int main() {
    string line;
    map<string, int> T;
    while(getline(cin, line)) {
        if(line == "***") break;
        T[line]++;
    }

    vis S;
    for(auto p: T) S.push_back(is(p.second, p.first));
    
    sort(S.rbegin(), S.rend());
    if(S[0].first == S[1].first)
        cout << "Runoff!" << endl;
    else
        cout << S[0].second << endl;
    return 0;
}
