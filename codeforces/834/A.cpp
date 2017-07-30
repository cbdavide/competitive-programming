#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b) {
    return (b + (a%b)) % b;
}

int main() {
    char s, e;
    int n;
    cin >> s >> e >> n;
    map <char, int> mci;
    mci['v'] = 0; mci['<'] = 1; mci['^'] = 2; mci['>'] = 3;
    int start = mci[s], end = mci[e];
    bool cw = (end == ((start + n) % 4));
    bool ccw = (end ==  mod(start - n, 4));
    if(cw && ccw) cout << "undefined\n";
    else if(cw) cout << "cw\n";
    else cout << "ccw\n";
    return 0;
}
