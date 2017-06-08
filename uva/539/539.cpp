#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool vis[26][26];

int dfs(vvi &adj, int s) {
    int size = 0;
    for(int i=0; i<adj[s].size(); i++) {
        int v = adj[s][i];
        if(!vis[s][v]) {
            vis[s][v] = vis[v][s] = true;
            size = max(size, dfs(adj, v) + 1);
            vis[s][v] = vis[v][s] = false; // Backtrack
        }
    }
    return size;
}

int main() {
    int V, E, u, v;
    while(cin >> V >> E && (V + E)) {
        vvi adj(V);
        for(int i=0; i<E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxi = 0;
        for(int i=0; i<V; i++) {
            memset(vis, 0, sizeof vis);
            maxi = max(maxi, dfs(adj, i));
        }
        cout << maxi << '\n';
    }
    return 0;
}
