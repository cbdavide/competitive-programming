#include <bits/stdc++.h>
using namespace std;

const int INF_MAX = 2147483647;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct nodo {
  int x, y, l;

  nodo(int i, int j, int le) {
    x = i;
    y = j;
    l = le;
  }
};

void bfs_f(char **maze, int **level, int r, int c) {
  queue<nodo> cola;

  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      if(maze[i][j] == '*'){
        level[i][j] = 0;
        cola.push(nodo(i, j, 0));
      }
    }
  }

  while(!cola.empty()) {
    nodo actual = cola.front();
    cola.pop();

    for(int i=0; i<4; i++) {
      int x = actual.x + dir[i][0];
      int y = actual.y + dir[i][1];

      if(x>=0 && x<r && y>=0 && y<c && maze[x][y]!='#' && level[x][y] > actual.l + 1) {
        level[x][y] = actual.l + 1;
        cola.push(nodo(x, y, actual.l + 1));
      }
    }
  }

}

void bfs_j(char **maze, int **level, int r, int c, nodo s) {

  queue<nodo> cola;
  cola.push(s);

  level[s.x][s.y] = s.l;

  while(!cola.empty()) {
    nodo actual = cola.front();
    cola.pop();

    for(int i=0; i<4; i++) {
      int x = actual.x + dir[i][0];
      int y = actual.y + dir[i][1];

      if(x>=0 && x<r && y>=0 && y<c && maze[x][y]!='#' && level[x][y] == INF_MAX) {
        level[x][y] = actual.l + 1;
        cola.push(nodo(x, y, actual.l + 1));
      }
    }
  }
}

void init(int **mat, int r, int c) {
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++)
      mat[i][j] = INF_MAX;
  }
}

int main() {
  int t, r, c, x, y;
  char **maze;
  int **time_j, **time_f;

  cin >> t;
  while(t--) {
    cin >> c >> r;

    maze = new char* [r];
    time_j = new int* [r];
    time_f = new int* [r];

    for(int i=0; i<r; i++) {
      maze[i] = new char[c];
      time_j[i] = new int[c];
      time_f[i] = new int[c];

      for(int j=0; j<c; j++)
        cin >> maze[i][j];
    }

    init(time_j, r, c);
    init(time_f, r, c);

    for(int i=0; i<r; i++) {
      for(int j=0; j<c; j++) {
        if(maze[i][j] == '@') {
          x = i;  y = j;
          i = r;  j = c;
        }
      }
    }

    bfs_j(maze, time_j, r, c, nodo(x, y, 0));
    bfs_f(maze, time_f, r, c);

    int minV = INF_MAX;

    for(int i=0; i<c; i++) {
      if(time_f[0][i] > time_j[0][i])
        minV = min(minV, time_j[0][i]);

      if(time_f[r - 1][i] > time_j[r - 1][i])
        minV = min(minV, time_j[r - 1][i]);
    }

    for(int i=0; i<r; i++) {
      if(time_f[i][0] > time_j[i][0])
        minV = min(minV, time_j[i][0]);

      if(time_f[i][c - 1] > time_j[i][c - 1])
        minV = min(minV, time_j[i][c - 1]);
    }

    if (minV == INF_MAX)
      cout << "IMPOSSIBLE\n";
    else
      cout << minV + 1 << '\n';

  }
  return 0;
}
