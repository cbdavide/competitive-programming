#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int counter, scc;
stack<int> comp;

void tarjanSCC(vvi &adj, vi &num, vi &low, vb &vis, int s) {
    low[s] = num[s] = counter++;
    comp.push(s);
    vis[s] = true;
    for(int j=0; j<(int)adj[s].size(); j++) {
        int v = adj[s][j];
        if(num[v] == -1) {
            tarjanSCC(adj, num, low, vis, v);
            low[s] = min(low[s], low[v]);
        }else if(vis[v]) {
            low[s] = min(low[s], num[v]);
        }
    }

    if(num[s] == low[s]) {
        scc++;
        while(true) {
            int cur = comp.top(); comp.pop();
            vis[cur] = false;
            if(cur == s) break;
        }
    }
}

int main() {
    int V, E, u, v, t;
    bool cond;
    while(cin >> V >> E && (V + E)) {
        vvi adj(V);
        for(int i=0; i<E; i++) {
            cin >> u >> v >> t;
            u--; v--;
            adj[u].push_back(v);
            if(t == 2) adj[v].push_back(u);
        }
        vi num(V, -1), low(V, 0);
        vb vis(V, 0);
        cond = true;
        counter = scc = 0;
        for(int i=0; i<V; i++) {
            if(num[i] == -1)
                tarjanSCC(adj, num, low, vis, i);
            if(scc > 1) {
                cond = false;
                break;
            }
        }
        cout << cond << '\n';
    }
    return 0;
}
