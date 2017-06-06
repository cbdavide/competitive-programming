#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int main() {
    int n, d, k, cont, t;
    while(cin >> n >> d >> k && (n + d + k)) {
        cont = 0;
        vi m(n), a(n);

        for(int i=0; i<n; i++) cin >> m[i];
        for(int i=0; i<n; i++) cin >> a[i];
        sort(m.begin(), m.end());
        sort(a.rbegin(), a.rend());

        for(int i=0; i<n; i++) {
            t = m[i] + a[i];
            if(t > d) cont += (t - d) * k;
        }
        cout << cont << '\n';
    }
    return 0;
}
