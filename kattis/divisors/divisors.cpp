#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define endl '\n'

typedef unsigned long long ll;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

typedef unordered_map<int, int> mii;
typedef vector<mii> vmii;

const int INF = ~(1<<31);
const int MAX = 500;

vi primes;
bitset<MAX> sieve;

void build() {
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for(ll i=2; i<MAX; i++) {
        if(sieve[i]) {
            for(int j=i*i; j<MAX; j+=i)
                sieve[j] = false;
            primes.PB((int)i);
        }
    }
}

mii factorization(int n) {
    int idx=0;

    mii A;
    while(n > 1 && idx < primes.size()) {
        while(n % primes[idx] == 0) {
            A[primes[idx]]++;
            n /= primes[idx];
        }
        idx++;
    }
    return A;
}

mii combination(vmii &T, int n, int k) {
    int mx = max(k, n - k);
    int mn = min(k, n - k);

    mii factors;
    for(int i=n; i>mx; i--)
        for(auto &p : T[i]) factors[p.F] += p.S;

    for(int i=2; i<=mn; i++)
        for(auto &p: T[i]) factors[p.F] -= p.S;

    return factors;
}

ll p(mii &T) {
    ll a = 1LL;
    for(auto &t : T) a *= t.S ? (t.S + 1) : 1LL;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    build();

    vmii A(432);
    for(int i=1; i<A.size(); i++)
        A[i] = factorization(i);

    int n, k;
    while(cin >> n >> k) {
        mii S = combination( A, n, k );
        cout <<  p( S ) << endl;
    }

    return 0;
}
