#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int, int>  ii;
typedef pair<ll, ii> lii;
typedef vector<lii> vlii;
typedef vector<int> vi;

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n)) {
        for(int i=0; i<n; i++) data[i] = i;
    }
    int find(int x) {
        if(data[x] == x) return x;
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

ll maximum(int V, vlii &E) {
    int x, y;
    ll w = 0;
    union_find uf(V);
    sort(E.rbegin(), E.rend());
    for(int i=0; i<E.size(); i++) {
        x = E[i].second.first;
        y = E[i].second.second;
        if(!uf.unite(x, y)) w += E[i].first;
    }
    return w;
}

int main() {
    int t, V, E, u, v;
    ll w;
    cin >> t;
    while(t--) {
        cin >> V >> E;
        vlii edges(E);
        for(int i=0; i<E; i++) {
            cin >> u >> v >> w;
            edges[i] = lii(w, ii(u, v));
        }
        cout << maximum(V + 1, edges) << '\n';
    }
    return 0;
}
