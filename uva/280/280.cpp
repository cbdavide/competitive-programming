#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

void dfs(int init, vvi &adj, vb &vis) {
  for (int i=0; i<adj[init].size(); i++) {
    if(!vis[adj[init][i]]) {
        vis[adj[init][i]] = true;
        dfs(adj[init][i], adj, vis);
    }
  }
}

int main() {
  int n, t, u, v, q, s, cont;
  while (cin >> n && n) {
    vvi adj(n+1);
    while (cin >> t && t) {
      while (cin >> u && u) {
        adj[t].push_back(u);
      }
    }

    cin >> q;
    for (int i=0; i < q; i++) {
      cont=0;
      vb vis(n+1, false);
      cin >> s;
      dfs(s, adj, vis);

      vi answ;

      for (int j=1; j< vis.size(); j++){
        if (!vis[j]){
          cont += 1;
          answ.push_back(j);
        }
    }
    cout << cont;
    for (int k=0; k<answ.size(); k++) {
        cout << ' ' << answ[k];
    }
      cout << endl;
    }
  }

  return 0;
}
