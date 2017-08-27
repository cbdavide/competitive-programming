#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for(int i=s; i<n; i++)
#define FI first
#define SE second

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n)) {
        rep(i, 0, n) data[i] = i;
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

vvii mst(int n, viii &E) {
    union_find uf(n); vvii G(n);
    sort(E.begin(), E.end());

    rep(i, 0, E.size()) {
        int x = E[i].SE.FI;
        int y = E[i].SE.SE;
        if(uf.unite(x, y)) {

            G[x].push_back(ii(y, E[i].FI));
            G[y].push_back(ii(x, E[i].FI));
        }
    }
    return G;
}

void dfs(vvii &G, vb &vis, vii &pi, int s, int t) {
    vis[s] = 1;
    rep(i, 0, G[s].size()) {
        int v = G[s][i].FI;
        if(!vis[v]) {
            // cout << s << ' ' << v << endl;
            pi[v] = ii(s, G[s][i].SE);
            if(v == t) return;
            dfs(G, vis, pi, v, t);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, N, R, u, v, l, q;
    cin >> t;
    rep(i, 1, t + 1) {
        cin >> N >> R;
        viii E(R);
        rep(j, 0, R) {
            cin >> u >> v >> l;
            E[j] = (iii(l, ii(u, v)));
        }
        vvii G = mst(N + 1, E);
        cin >> q;
        cout << "Case " << i << '\n';
        while (q--) {
            cin >> u >> v;
            vb vis(G.size(), 0);
            vii pi(G.size());
            pi[u] = ii(0, 0);
            dfs(G, vis, pi, u, v);

            int maxi = -1;
            while(pi[v].FI != 0) {
                maxi = max(pi[v].SE, maxi);
                v = pi[v].FI;
            }
            cout << maxi << endl;
        }
        cout << '\n';

    }
    return 0;
}
