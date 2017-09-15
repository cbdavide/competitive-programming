#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int dfs(vvi &G, int s, vi &vis, vi &conter) {
    vis[s] = 1; conter[s] = 0;
    for(int i=0; i<G[s].size(); i++) {
        int v = G[s][i];
        if(!vis[v]) {
            conter[v] = dfs(G, v, vis, conter);
            conter[s] += conter[v] + 1;
        }
    }
    return conter[s];
}

int main() {
    int V, k, v;
    while(cin >> V && V) {
        vvi G(V + 1);
        for(int i=1; i<=V; i++) {
            cin >> k;
            for(int j=0; j<k; j++) {
                cin >> v;
                G[i].push_back(v);
            }
        }
        vi vis(V + 1), conter(V + 1), answ(V + 1);
        for(int i=1; i<=V; i++) {
            answ[i] = dfs(G, i, vis, conter);
            vis = vi(V + 1); conter = vi(V + 1);
        }

        int maxi = *max_element(answ.begin(), answ.end());
        for(int i=1; i<=V; i++) {
            if(maxi == answ[i]) {
                cout << i << '\n';
                break;
            }
        }

    }

    return 0;
}
