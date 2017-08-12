#include <bits/stdc++.h>
using namespace std;

int coins[5] = {1, 5, 10, 25, 50};
long long dp[30001];

void f(){
    dp[0] = 1LL;
    for(int i=0; i<5; i++) {
        for(int j=coins[i]; j<=30000; j++)
            dp[j] += dp[j - coins[i]];
    }
};

int main() {
    f();
    int n;
    while(cin >> n) {
        if(dp[n] == 1){
            cout << "There is only 1 way to produce "
                 << n << " cents change.\n";
        } else {
            cout << "There are "<< dp[n] << " ways to produce "
                 << n << " cents change.\n";
        }
    }
    return 0;
}
