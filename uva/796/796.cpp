#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

vi num, low, parent;
vii answ;
int cont;

void bridges(vvi &adj, int u) {
    low[u] = num[u] = cont++;
    for(int j=0; j<(int)adj[u].size(); j++) {
        int v = adj[u][j];
        if(num[v] == -1) {
            parent[v] = u;
            bridges(adj, v);
            if(low[v] > num[u])
                answ.push_back(ii(min(u, v), max(u,v)));
            low[u] = min(low[u], low[v]);
        } else if(v != parent[u]) {
            low[u] = min(low[u], num[v]);
        }
    }
}

int main() {

    char gra;
    int V, root, n, t;
    string line;

    while(cin >> V) {

        vvi G(V);
        num.assign(V, -1); low.assign(V, 0);
        parent.assign(V, 0); cont = 0;
        answ.clear();

        getline(cin, line);

        for(int i=0; i<V; i++) {
            getline(cin, line);

            stringstream ss(line);
            ss >> root;
            ss >> gra >> n >> gra;
            for(int j=0; j<n; j++) {
                ss >> t;
                G[root].push_back(t);
                G[t].push_back(root);
            }
        }

        for(int i=0; i<V; i++) {
            if(num[i] == -1)
                bridges(G, i);
        }
        sort(answ.begin(), answ.end());
        cout << answ.size() << " critical links\n";
        for(int i=0; i<answ.size(); i++)
            cout << answ[i].F << " - " << answ[i].S << '\n';
        cout << '\n';
    }
    return 0;
}
