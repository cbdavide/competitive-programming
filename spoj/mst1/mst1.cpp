#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

// map<int, int> T;
int T[(int)1e7 + 7];

int f(int n) {
    if(n == 1) return 0;
    if(T[n]) return T[n];
    T[n] = INF;
    T[n] = min(T[n], f(n - 1) + 1);
    // cout << T[n] << endl;
    if(n % 2 == 0) T[n] = min(T[n], f(n / 2) + 1);
    // cout << T[n] << endl;
    if(n % 3 == 0) T[n] = min(T[n], f(n / 3) + 1);
    // cout << T[n] << endl;
    return T[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(T, 0, sizeof(int) * (1e7 + 7));
    int t, n;
    cin >> t;
    T[1] = 0; T[2] = 1; T[3] = 1;
    // for(int i=4; i<2e7 + 7; i++) {
    //     T[i] = 1e8;
    //     T[i] = min(T[i], T[i - 1]) + 1;
    //     if(i % 2 == 0) T[i] = min(T[i], T[i / 2]) + 1;
    //     if(i % 3 == 0) T[i] = min(T[i], T[i /3]) + 1;
    //     cout << i << ": " << T[i] << endl;
    // }
    for(int i=1; i<=t; i++) {
        cin >> n;
        cout << "Case " << i << ": " << f(n) << '\n';
    }
    return 0;
}
