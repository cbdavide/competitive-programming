#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef map<int, int> mii;

int dfs(vi &adj, vb &st, vi &reach, int s) {
    st[s] = true;
    int v = adj[s], total = 0;
    if(!st[v]) total = dfs(adj, st, reach, v) + 1;
    st[s] = false;
    return reach[s] = total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, u, v;
    cin >> t;
    for(int z=1; z<=t; z++) {
    cin >> n; vi adj(n + 1);
    for(int i=0; i<n; i++) {
        cin >> u >> v;
        adj[u] = v;
    }
    vb vis(n + 1); vi reach(n + 1, -1);
    int idx = 1, max_c = 0;
    for(int i=1; i<=n; i++) {
        if(reach[i] == -1) dfs(adj, vis, reach, i);
        if(reach[i] > max_c) {
            max_c = reach[i];
            idx = i;
        }
    }
    cout << "Case " << z << ": " << idx << '\n';
  }

  return 0;
}
