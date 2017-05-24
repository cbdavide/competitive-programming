#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

void dfs(vvi &adj, vb &vis, int s) {
    vis[s] = 1;
    for(int i : adj[s]) {
        if(!vis[i]) {
            dfs(adj, vis, i);
        }
    }
}

int main() {
    int t, V, E, u, v, cont;
    cin >> t;
    while(t--) {
        cin >> V >> E;
        vvi adj(V);
        for(int i=0; i<E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cont = 0;
        vb vis(V, 0);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(adj, vis, i);
                cont++;
            }
        }
        cout << cont - 1 << '\n';
    }
    return 0;
}
