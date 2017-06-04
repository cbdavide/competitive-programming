#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef map<string, int> msi;

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n)) {
        for(int i=0; i<n; i++) data[i] = i;
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

int mst(int V, viii &E) {
    int w = 0;
    union_find uf(V);
    sort(E.begin(), E.end());
    for(int i=0; i<E.size(); i++) {
        int x = E[i].second.first;
        int y = E[i].second.second;
        if(uf.unite(x, y)){
            w += E[i].first;
        }
    }
    return w;
}

int main() {
    int t, w, V, E, cont, cost;
    string v, u;

    cin >> t;
    for(int i=0; i<t; i++) {
        if(i > 0) cout << '\n';
        msi maper; cont = 1;

        cin >> V >> E;
        viii edges;
        for(int i=0; i<E; i++) {
            cin >> u >> v >> w;
            if(maper[u] == 0) maper[u] = cont++;
            if(maper[v] == 0) maper[v] = cont++;
            edges.push_back(iii(w, ii(maper[u], maper[v])));
        }
        cost = mst(V + 1, edges);
        cout << cost << '\n';
    }

    return 0;
}
