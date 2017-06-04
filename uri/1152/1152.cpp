#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
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

int mst(int V, viii &E) {
    int x, y, w = 0;
    union_find uf(V);
    sort(E.begin(), E.end());
    for(int i=0; i<E.size(); i++) {
        x = E[i].second.first;
        y = E[i].second.second;
        if(uf.unite(x, y)) w += E[i].first;
    }
    return w;
}

int main() {
    int V, E, u, v, w, cont;
    while(cin >> V >> E && (V + E)) {
        cont = 0;
        viii edges(E);
        for(int i=0; i<E; i++) {
            cin >> u >> v >> w;
            cont += w;
            edges[i] = iii(w, ii(u, v));
        }
        cout << (cont - mst(V, edges)) << '\n';
    }
    return 0;
}
