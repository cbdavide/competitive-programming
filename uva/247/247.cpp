#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<string, int> msi;
typedef map<int, string> mis;


int cont;
stack<int> comp;
msi names;
mis otherway;

void scc(vvi &adj, vi &low, vi &num, vb &inComp, int u) {
    low[u] = num[u] = cont++;
    comp.push(u);
    inComp[u] = true;
    for(int i=0; i<(int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(num[v] == -1) {
            scc(adj, low, num, inComp, v);
            low[u] = min(low[u], low[v]);
        }else if(inComp[v]) {
            low[u] = min(low[u], num[v]);
        }
    }
    if(num[u] == low[u]) {
        while(true) {
            int cur = comp.top(); comp.pop();
            inComp[cur] = false;
            cout << otherway[cur];
            if(cur == u) {
                cout << '\n';
                break;
            } else cout << ", ";
        }
    }
}

int main() {
    int V, E, cas = 1, vertex;
    string u, v;
    while(cin >> V >> E && (V + E )) {
        if(cas > 1) cout << '\n';
        vertex = 1;

        names.clear(); otherway.clear();
        vvi adj(V + 1);
        vi num(V + 1, -1), low(V + 1, 0);
        vb comp(V + 1, 0);

        for(int i=0; i<E; i++) {
            cin >> u >> v;
            if(names[u] == 0){
                names[u] = vertex++;
                otherway[vertex - 1] = u;
            }
            if(names[v] == 0){
                names[v] = vertex++;
                otherway[vertex - 1] = v;
            }
            adj[names[u]].push_back(names[v]);
        }

        cont = 1;
        printf("Calling circles for data set %d:\n", cas++);
        for(int i=1 ; i<adj.size(); i++) {
            if(num[i] == -1) {
                scc(adj, low, num, comp, i);
            }
        }
    }
    return 0;
}
