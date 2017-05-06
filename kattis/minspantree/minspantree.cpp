#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;
typedef vector<pii> vpii;
typedef vector<edge> E;

int weight;

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
        int px = find(x);
        int py = find(y);
        if(px == py) return false;
        if(pe[px] > pe[py]) swap(px, py);
        pe[px] += pe[py];
        data[py] = px;
        return true;
    }
};

vpii mst(int n, E &edges) {
    weight = 0;
    union_find uf(n);
    sort(edges.begin(), edges.end());
    vpii res;
    for(int i=0; i<edges.size(); i++) {
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        if(uf.find(x) != uf.find(y)) {
            weight += edges[i].first;
            res.push_back(pii(min(x, y), max(x, y)));
            uf.unite(x, y);
        }
    }
    return res;
}

int main() {
    int v, e, x, y, w;
    while(scanf("%d %d %d", &);)
    while(cin >> v >> e && (v + e)) {
        E list(e);
        for(int i=0; i<e; i++) {
            cin >> x >> y >> w;
            list[i] = edge(w, pii(x, y));
        }
        vpii answ = mst(v, list);
        if(answ.size() > 0) {
            printf("%d\n", weight);
            sort(answ.begin(), answ.end());
            for(int i=0; i<answ.size(); i++){
                printf("%d %d\n", answ[i].first, answ[i].second);
            }
        }
        else printf("Impossible\n");
    }
    return 0;
}
