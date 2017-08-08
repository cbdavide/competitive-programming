#include <bits/stdc++.h>
using namespace std;

int f(int *V, int *W, int n, int k) {
    int dp[n + 1][k + 1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=k; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j];
                if(j - W[i - 1] >= 0){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i - 1]] + V[i -1]);
                }
            }
        }
    }
    return dp[n][k];
}

int main() {
    int n, k, capacity, resistance;
    int *V, *W;
    cin >> n;
    while(n--) {
        cin >> k;
        V = new int[k];
        W = new int[k];
        for(int i=0; i<k; i++)
            cin >> V[i] >> W[i];
        cin >> capacity >> resistance;
        if(f(V, W, k, capacity) >= resistance)
            cout << "Missao completada com sucesso\n";
        else
            cout << "Falha na missao\n";
    }
    return 0;
}
