#include <bits/stdc++.h>
using namespace std;

#define INF 2e8

typedef pair <int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool bellman(vii *graph, int n, int s) {
    vi dist(n, INF);
    dist[s] = 0;
    for(int i=0; i<n - 1; i++) {
        for(int u=0; u<n; u++) {
            for(ii v : graph[u]) {
                dist[v.first] = min(dist[v.first], v.second + dist[u]);
            }
        }
    }
    for(int u=0; u<n; u++) {
        for(ii v : graph[u]) {
            if(v.second + dist[u] < dist[v.first])
                return true;
        }
    }
    return false;
}

int main() {
    int t, V, E, u, v, w;
    vii *adj;

    cin >> t;
    while(t--) {
        cin >> V >> E;
        adj = new vii[V];
        for(int i=0; i<E; i++) {
            cin >> u >> v >> w;
            adj[u].push_back(ii(v, w));
        }
        if(bellman(adj, V, 0)) cout << "possible\n";
        else cout << "not possible\n";
    }
    return 0;
}
