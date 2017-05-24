#include <bits/stdc++.h>
using namespace std;

#define ll double

ll factorial(ll n) {
    if(n < 2) return 1;
    if(n < 13) return n * factorial(n - 1);
    return -1;
}

ll operate(ll n, int t) {
    if(t == 1) return factorial(n);
    if(t == 2) return pow(2, n);
    if(t == 3) return pow(n, 4);
    if(t == 4) return pow(n, 3);
    if(t == 5) return pow(n, 2);
    if(t == 6) return (n * log2(n));
    return n;
}

int main() {
    ll m, n, r;
    int t;
    cin >> m >> n >> t;
    r = operate(n, t);
    if(r != -1 && r <= m) cout << "AC\n";
    else cout << "TLE\n";
    return 0;
}
