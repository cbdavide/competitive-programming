#include <iostream>
using namespace std;

const int INF = 1e9 + 10;

int p(int l, int r) {
    if(r > l) return r - l;
    return 0;
}

int main() {
    int n, l, r, l1, l2, r1, r2;

    cin >> n;
    l1 = -INF; r1 = INF;
    for(int i=0; i<n; i++) {
        cin >> l >> r;
        l1 = max(l1, l);
        r1 = min(r1, r);
    }

    cin >> n;
    l2 = -INF; r2 = INF;
    for(int i=0; i<n; i++) {
        cin >> l >> r;
        l2 = max(l2, l);
        r2 = min(r2, r);
    }

    cout << max(p(r1, l2), p(r2, l1)) << '\n';
    return 0;
}
