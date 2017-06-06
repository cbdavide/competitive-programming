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

viii mst(int V, viii &E) {
    viii answ;
    int x, y;
    union_find uf(V);
    sort(E.begin(), E.end());
    for(int i=0; i<E.size(); i++) {
        x = E[i].second.first;
        y = E[i].second.second;
        if(uf.unite(x, y)) answ.push_back(E[i]);
    }
    return answ;
}

int main() {
    int t, V, w;
    char garbage;
    cin >> t;
    for(int cas=1; cas<=t; cas++) {
        cin >> V;
        viii edges, answ;
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                cin >> w;
                if(j < V - 1) cin >> garbage;
                if(w != 0 )
                    edges.push_back(iii(w, ii(i, j)));
            }
        }
        answ = mst(27, edges);
        cout << "Case " << cas << ":\n";
        for(int i=0; i<answ.size(); i++) {
            cout << (char)(answ[i].second.first + 65) << '-'
                 << (char)(answ[i].second.second + 65) << ' '
                 << answ[i].first << '\n';
        }
    }
    return 0;
}
