#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, x, n, k, least, most;
    cin >> t;
    while(t--) {
        cin >> x >> n;
        int mini[n], maxi[n];
        for(int i=0; i<n; i++){
            cin >> k;
            mini[i] = min(k, abs(k - x));
            maxi[i] = max(k, abs(k - x));
        }

        least = *max_element(mini, mini + n);
        most = *max_element(maxi, maxi + n);

        cout << least << ' ' << most << '\n';

    }
    return 0;
}
