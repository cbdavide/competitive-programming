#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef vector<ll> vll;

struct fenwick_tree {
    int n; vll data;
    fenwick_tree(int _n) : n(_n), data(vll(_n)) { }
    void update(int x, ll val) {
        while(x < n) {
            data[x] += val;
            x |= x + 1;
        }
    }
    ll query(int x) {
        ll res = 0;
        while(x >= 0) {
            res += data[x];
            x = (x & (x + 1)) - 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, a, b;
    char op;
    cin >> n >> q;
    fenwick_tree *tree = new fenwick_tree(n+1);
    for(int i=0; i<q; i++) {
        cin >> op;
        if(op == '+') {
            cin >> a >> b;
            tree->update(a, b);
        } else {
            cin >> a;
            cout << tree->query(--a) << '\n';
        }
    }
    return 0;
}
