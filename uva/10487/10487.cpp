#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, e) for(int i=s; i<e; i++)

int main() {
    int n, q, t, z = 1;
    long long result, fallback;
    while(cin >> n && n) {
        long long nums[n];
        rep(i, 0, n) cin >> nums[i];
        cin >> q;
        cout << "Case " << z++ << ":\n";
        while(q--) {
            result = 1e9; fallback = 1e9;
            cin >> t;
            rep(i, 0, n) {
                rep(j, i + 1, n) {
                    if(abs(t - (nums[i] + nums[j])) < result) {
                        result = abs(t - (nums[i] + nums[j]));
                        fallback = nums[i] + nums[j];
                    }
                }
            }
            cout << "Closest sum to " << t << " is " << fallback << ".\n";
        }
    }
    return 0;
}
