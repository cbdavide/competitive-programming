#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX (ll)1<<60

typedef unsigned int ui;
typedef vector<ll> vi;

int main() {
    ll n, m, z;
    vi factors;

    for(int i=0; i<32; i++) {
        for(int j=0; j<32; j++) {
            z = pow(2, i) * pow(3, j);
            if(z <= MAX) factors.push_back(z);
        }
    }

    sort(factors.begin(), factors.end());
    while(cin >> m && m) {
        cout << *lower_bound(factors.begin(), factors.end(), m) << '\n';
    }

    return 0;
}
