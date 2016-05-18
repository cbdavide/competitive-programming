#include <bits/stdc++.h>
using namespace std;

int main() {
    long long max, cont = 0;
    int q, root, t;
    bool *sieve;

    cin >> max >> q;
    sieve = new bool[max + 1];
    memset(sieve, 1, sizeof(bool) * (max + 1));

    sieve[0] = 0;
    sieve[1] = 0;

    root = sqrt(max);
    for(int m = 2; m <= root; m++){
        if(sieve[m]) {
            for(int k = m*m; k <= max; k += m) {
                sieve[k] = 0;
            }
        }
    }

    for(int i=0; i<=max; i++) {
        if(sieve[i])
            cont++;
    }

    cout << cont << '\n';
    for(int i=0; i<q; i++){
        cin >> t;
        cout << sieve[t] << '\n';
    }


    return 0;
}
