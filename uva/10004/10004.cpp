#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

bool dfs(vi *graph, vb &vis, vi &color, int s, int c) {
    vis[s] = true;
    color[s] = c;
    for(int v: graph[s]) {
        if(!vis[v]) {
            int d = c == 0 ? 1 : 0;
            return dfs(graph, vis, color, v, d);
        }else {
            if(color[v] == color[s])
                return false;
        }
    }
    return true;
}

int main() {
    int v, e, a, b;
    while(cin >> v && v) {
        vi *adj = new vi[v];
        vb visited(v, 0);
        vi color(v, -1);

        cin >> e;
        for(int i=0; i<e; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(dfs(adj, visited, color, 0, 0))
            cout << "BICOLORABLE.\n";
        else
            cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
