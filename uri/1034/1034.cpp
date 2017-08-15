#include <bits/stdc++.h>
using namespace std;

int f(int *T, int n, int w) {
    int dp[w + 1];
    for(int i=0; i<=w; i++) dp[i] = 1e9;
    dp[0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=T[i]; j<=w; j++) {
            if(j - T[i] >= 0)
                dp[j] = min(dp[j], dp[j - T[i]] + 1);
        }
    }
    return dp[w];
}

int main() {
    int t, n, w, *T;
    cin >> t;
    while(t--) {
        cin >> n >> w;
        T = new int[n];
        for(int i=0; i<n; i++) cin >> T[i];
        cout << f(T, n, w) << '\n';
    }
    return 0;
}
