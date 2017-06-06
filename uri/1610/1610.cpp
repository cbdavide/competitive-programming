#include <bits/stdc++.h>
using namespace std;

enum {WHITE, GRAY, BLACK};

typedef vector<int> vi;
typedef vector<vi> vvi;

bool cond;

void dfs(vvi &adj, vi &vis, int s) {
    vis[s] = GRAY;
    for(int i=0; i<adj[s].size(); i++) {
        int v = adj[s][i];
        if(vis[v] == WHITE){
            dfs(adj, vis, v);
        }else if(vis[v] == GRAY){
            cond = true;
            return;
        }
    }
    vis[s] = BLACK;
}

int main() {
    int t, V, E, u, v;

    cin >> t;
    while(t--) {
        cin >> V >> E;
        vvi adj(V + 1);
        for(int i=0; i<E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        cond = false;
        vi visited(V + 1, WHITE);
        for(int i=1; i<adj.size(); i++) {
            if(visited[i] == WHITE) {
                dfs(adj, visited, i);
                if(cond) break;
            }
        }
        if(cond) cout << "SIM\n";
        else cout << "NAO\n";
    }
    return 0;
}
