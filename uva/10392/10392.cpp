#include <bits/stdc++.h>
using namespace std;

int main() {

    unsigned long long n, root;
    vector<int> primes;
    vector<bool> sieve(10000000, 1);

    sieve[0] = 0;
    sieve[1] = 0;

    root = sqrt(10000000);
    for(int m=2; m<=root; m++) {
        if(sieve[m]) {
            for(int r=m*m; r<10000000; r+=m) {
                sieve[r] = 0;
            }
        }
    }
    for(int i=0; i<10000000; i++) {
        if(sieve[i]) {
            primes.push_back(i);
        }
    }

    while(cin >> n && n != -1) {
        root = sqrt(n);
        for(int i=0; i< primes.size() && primes[i] <= root; i++) {
            while(n % primes[i] == 0) {
                cout << "    " << primes[i] << '\n';
                n /= primes[i];
            }
        }

        if(n != 1)
            cout << "    " << n << '\n';

        cout << '\n';
    }
}
