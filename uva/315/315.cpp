#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

vb art;
vi num, low, parent;
int cont, root, root_children;

void articulation(vvi &adj, int u) {
    low[u] = num[u] = cont++;
    for(int j=0; j<(int)adj[u].size(); j++) {
        int v = adj[u][j];
        if(num[v] == -1) {
            parent[v] = u;
            if(u == root) root_children++;
            articulation(adj, v);
            if(low[v] >= num[u])
                art[u] = true;
            low[u] = min(low[u], low[v]);
        } else if(v != parent[u]) {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {
    string line;
    int V, u, v;
    while(cin >> V && V) {
        V++;
        vvi adj(V);
        num.assign(V, -1); low.assign(V, 0);
        art.assign(V, 0); parent.assign(V, 0);
        cont = 0;
        while(cin >> u && u) {
            // cout << u;
            getline(cin, line);
            stringstream ss(line);
            while(ss >> v) {
                // cout << ' ' << v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            // cout << endl;
        }
        for(int j=1; j<V; j++) {
            if(num[j] == - 1) {
                root = j; root_children = 0;
                articulation(adj, j);
                art[root] = (root_children > 1);
            }
        }
        int answ = 0;
        for(int j=1; j<V; j++) {
            if(art[j]) answ++;
        }
        cout << answ << '\n';
    }
    return 0;
}
