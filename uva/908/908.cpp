#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int, int> ii;
typedef pair<int, ii> edge;
typedef vector<edge> E;
typedef vector<int> vi;

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n)) {
        for(int i=0; i<data.size(); i++)
            data[i] = i;
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
    }
};

int mst(int n, E &edges) {
    int w = 0;
    union_find uf(n);
    sort(edges.begin(), edges.end());
    for(int i=0; i<edges.size(); i++) {
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        if(uf.find(x) != uf.find(y)) {
            w += edges[i].first;
            uf.unite(x, y);
        }
    }
    return w;
}

int main() {
    int V, u, v, w, first, second;
    int K;
    int cont = 1;
    while(cin >> V) {
        if((cont++) > 1) cout << '\n';
        E edges;
        first = 0;
        for(int i=1; i<V; i++) {
            cin >> u >> v >> w;
            first += w;
        }
        cin >> K;
        for(int i=0; i<K; i++) {
            cin >> u >> v >> w;
            edges.push_back(edge(w, ii(u, v)));

        }
        cin >> K;
        for(int i=0; i<K; i++) {
            cin >> u >> v >> w;
            edges.push_back(edge(w, ii(u, v)));
        }
        second = mst(V + 1, edges);
        cout << first << '\n' << second << endl;
    }
    return 0;
}
