#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n, 1)) {
        for(int i=0; i<data.size(); i++) data[i] = i;
    }
    int find(int x) {
        if(x == data[x]) return x;
        data[x] = find(data[x]);
        return data[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        if(pe[px] > pe[py]) swap(px, py);
        pe[px] += pe[py];
        data[py] = px;
        return true;
    }
};

int main() {
    int n, m, t, u, a;
    while(cin >> n >> m && (n + m)) {
        union_find s(n);

        for(int i=0; i<m; i++) {
            a = -1;
            cin >> t;
            for(int j=0; j<t; j++) {
                cin >> u;
                if(a == -1) a = u;
                else s.unite(a, u);
            }
        }
        cout << s.pe[s.find(0)] << '\n';
    }
    return 0;
}
