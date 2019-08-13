#include <bits/stdc++.h>
using namespace std;

string S;
string T = "welcome to code jam";
int dp[507][507];

int f(int i, int j) {
    if(j < 0) return 1;
    if(i < 0) return 0;

    if(~dp[i][j]) return dp[i][j];

    dp[i][j] = f(i - 1, j);

    if(S[i] == T[j]) 
        dp[i][j] = ((dp[i][j] * 1LL) + f(i - 1, j - 1)) % 10000;

    return dp[i][j];
}

int main(){
    int t;
    cin >> t;
    getline(cin, S);
    for(int i=1; i<=t; i++) {
        getline(cin, S);
        memset(dp, -1, sizeof dp);
        printf("Case #%d: %04d\n", i, f(S.size(), T.size()));
    }
    return 0;
}
