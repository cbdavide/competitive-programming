#include <bits/stdc++.h>
using namespace std;

bool* fillSieve(int limit) {
    bool *sieve = new bool[limit + 1];
    int root;

    memset(sieve, 1, sizeof(bool) * (limit + 1));

    sieve[0] = 0;
    sieve[1] = 0;

    root = sqrt(limit);
    for(int m = 2; m <= root; m++) {
        if(sieve[m]) {
            for(int k = m * m; k <= limit; k += m)
                sieve[k] = 0;
        }
    }

    return sieve;
}

int main() {
    int n, m, cont = 0;
    bool *sieve;

    cin >> n >> m;

    sieve = fillSieve(m);

    for(int i=n; i<=m; i++) {
        for(int j = i+1; j<=m; j++) {
            if(sieve[i] && sieve[j] && abs(i - j) == 2)
                cont++;
        }
    }

    cout << cont << '\n';
    
    return 0;
}
