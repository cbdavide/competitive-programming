#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;

void bfs(vvi adjList, int *level, int start) {

  level[start] = 0;
  qi cola;

  cola.push(start);

  while(!cola.empty()) {
    int actual = cola.front();

    vi adj = adjList[actual];

    for(int i=0; i<adj.size(); i++) {
      if(level[adj[i]] == -1) {
        level[adj[i]] = level[actual] + 1;
        cola.push(adj[i]);
      }
    }
    cola.pop();
  }
}

int main() {
  int t, v, a, v1, v2, s;
  int *level;

  cin >> t;
  while(t--) {
    cin >> v >> a;
    vvi adjList(v + 1);
    level = new int[v + 1];

    for(int i=0; i<a; i++) {
      cin >> v1 >> v2;
      adjList[v1].push_back(v2);
      adjList[v2].push_back(v1);
    }

    cin >> s;

    for(int i=0; i<=v; i++)
      level[i] = - 1;

    //BFS ALgorithm
    bfs(adjList, level, s);

    for(int i=1; i<=v; i++) {
      if(i != s) {
        int r = (level[i] == -1) ? -1 : level[i] * 6;
        cout << r;

        if(i<v)
          cout << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}
