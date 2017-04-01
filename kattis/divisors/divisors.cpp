#include <iostream>
#include <cmath>
#include <map>
using namespace std;

#define ll long long

typedef map<int, ll> mii;

mii factorial;
mii divisors;

ll f(ll n) {
    if(factorial[n])
        return factorial[n];

    factorial[n] = n * f(n - 1);
    return factorial[n];
}

ll generate(ll n, ll m) {
    int t = n - m;
    ll answ = 1;
    for(int i=0; i<t; i++)
        answ *= n--;
    return answ;
}

int d(ll n) {
    if(divisors[n])
        return divisors[n];

    int cont = 0;
    int lim = ceil(sqrt(n));

    for(int i=1; i<lim; i++) {
        if(n % i == 0) {
            cont++;

            if(i != lim)
                cont++;
        }
    }

    divisors[n] = (ll)cont;
    return divisors[n];
}

int main() {
    factorial[(ll)0] = 1, factorial[(ll)1] = 1;
    divisors[(ll)1] = 1;

    ll n, k, t, num, den;
    while(cin >> n >> k){
        den = min(k, (n - k));
        num = generate(n, max(k, (n - k)));
        cout << d(num / f(den)) << '\n';
    }
    return 0;
}
