#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct RUPQ {
    vi tree;
    RUPQ(int n) : tree(vi(n + 1)) {}
    void update(int k, int v) {
        while(k < tree.size()) {
            tree[k] += v;
            k += k & (-k);
        }
    }
    void range_update(int l, int r) {
        update(l, 1);
        update(r + 1, -1);
    }
    int query(int l) {
        int sum = 0;
        while(l > 0) {
            sum += tree[l];
            l -= l & (-l);
        }
        return sum;
    }
};

int main() {
    int n, l, r, a, pa, pb;
    RUPQ *fenwick = new RUPQ(100000);
    vector<int> cont(1000005);
    cin >> n;
    while(n--) {
        a = 0;
        scanf("%d %d", &l, &r);

        pa = fenwick->query(l);
        pb = fenwick->query(r);

        printf("%d\n", pa + pb - cont[l] - cont[r]);
        cont[l] = pa;
        cont[r] = pb;

        fenwick->range_update(l + 1, r - 1);
    }
    return 0;
}
