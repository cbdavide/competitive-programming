#include <bits/stdc++.h>
using namespace std;

int *V, *W;

int f(int *V, int *W, int n, int w) {
    int dp[n + 1][w + 1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=w; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j];
                if(j - W[i - 1] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i - 1]] + V[i - 1]);
                }
            }
        }
    }
    return dp[n][w];
}

int main() {
    int t, p, w;
    cin >> t;
    for(int z=1; z<=t; z++){
        cin >> p >> w;
        V = new int[p];
        W = new int[p];
        for(int i=0; i<p; i++)
            cin >> V[i] >> W[i];
        cout << "Galho " <<  z << ":\n"
             << "Numero total de enfeites: "
             << f(V, W, p, w) << "\n\n";
    }
    return 0;
}
