#include <bits/stdc++.h>
using namespace std;

string s;
string p = "abcdefghijklmnopqrstuvwxyz";

int dp[100][100];

int f(int i, int j) {
    if(j == p.size()) return 0;
    if(i == s.size()) return p.size() - j;

    if(~dp[i][j]) return dp[i][j];
    
    int &r = dp[i][j];

    r = f(i + 1, j);
    if(s[i] == p[j])
        r = min(r, f(i + 1, j + 1));
    else 
        r = min(r, f(i, j + 1) + 1);

    return r;
}

int main() {
    cin >> s;    
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << endl;
    return 0;
}
