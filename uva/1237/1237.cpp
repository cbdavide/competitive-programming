#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, q, a, b, k;
    cin >> t;
    for(int z=0; z<t; z++) {
        if(z > 0)
            cout << '\n';
        cin >> n;
        string car;
        string names[n];
        int lowers[n], highers[n];
        for(int i=0; i<n; i++) {
            cin >> car >> a >> b;
            names[i] = car;
            lowers[i] = a;
            highers[i] = b;
        }
        cin >> q;
        while(q--) {
            cin >> a;
            int cont = 0;
            k = -1;
            for(int i=0; i<n; i++) {
                if(cont == 2) {
                    i = n + 3;
                    k = -1;
                    continue;
                }
                if(a > lowers[i] && a< highers[i]) {
                    k = i;
                    cont++;
                }
            }
            if(cont == 2) k = -1;
            if(k >= 0) {
                cout << names[k] << '\n';
            }else {
                cout << "UNDETERMINED\n";
            }
        }
    }
    return 0;
}
