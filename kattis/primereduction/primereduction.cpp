#include <bits/stdc++.h>
using namespace std;

vector<long long> prime_factors(long long n) {
    long long root;
    vector<long long> factors;

    while(n%2 == 0) {
        n /= 2;
        factors.push_back(2);
    }

    root = sqrt(n);

    for(int i=3; i<=root; i += 2){
        while(n%i == 0) {
            n /= i;
            factors.push_back(i);
        }
    }

    if(n > 2)
        factors.push_back(n);

    return factors;
}

long long reduce(vector<long long> factors) {
    long long r = 0;
    for(int i=0; i<factors.size(); i++)
        r += factors[i];
    return r;
}

main() {
    long long n, cont;
    vector<long long> factors;

    while(cin >> n && n != 4) {
        cont = 1;

        factors = prime_factors(n);

        while(factors.size() != 1) {
            n = reduce(factors);
            factors = prime_factors(n);
            cont ++;
        }

        cout << n << ' ' << cont << '\n';
    }
}
