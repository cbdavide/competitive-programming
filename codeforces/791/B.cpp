#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(int nodo, vvi &list, vb &visited, int &nodos, int &vertices) {
  visited[nodo] = 1;

  nodos++;
  vertices += list[nodo].size();

  for(auto n : list[nodo]) {
    if(!visited[n])
      dfs(n, list, visited, nodos, vertices);
  }
}

int main() {
  int n, m, a, b;
  cin >> n >> m;

  vvi list(n + 1);
  vb visited(n + 1, 0);

  for(int i=0; i<m; i++) {
    cin >> a >> b;
    list[a].push_back(b);
    list[b].push_back(a);
  }

  bool cond = 1;
  for(int i=1; i<=n; i++) {
    int nodos = 0, aristas = 0;
    if(!visited[i]) {
      dfs(i, list, visited, nodos, aristas);
      if(aristas != (long long) nodos * (nodos - 1)) {
        cond = 0;
        i = n + 1;
      }
    }
  }

  if(cond) cout << "YES\n";
  else cout << "NO\n";

  return 0;
}
