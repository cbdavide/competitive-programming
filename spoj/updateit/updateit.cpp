#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct RUPQ {
    vi data;
    RUPQ(int n) : data(vi(n + 1)) {}
    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += data[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
    void update(int idx, int val) {
        while(idx < data.size()) {
            data[idx] += val;
            idx += idx & (-idx);
        }
    }
    void range_update(int a, int b, int v) {
        update(a, v);
        update(b + 1, -v);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, n, u, k;
    int a, b, val;
    cin >> t;
    while(t--) {
        cin >> n >> u;
        RUPQ *tree = new RUPQ(n);
        for(int i=0; i<u; i++) {
            cin >> a >> b >> val;
            tree->range_update(++a, ++b, val);
        }
        cin >> k;
        while(k--) {
            cin >> a;
            cout << tree->query(++a) << '\n';
        }
    }
    return 0;
}
