#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
bool visited[100][100];
int cont;

void clean() {
  for(int i=0;i<100; i++) {
    for(int j=0; j<100; j++)
      visited[i][j] = 0;
  }
}

void dfs (vs &mat, int a, int b) {
  if(a < 0 || a  >= mat.size())
      return;
  if(b < 0 || b >= mat[a].size())
      return;

  if(visited[a][b]) return;

  if(mat[a][b] != 'W'){
    return;
  }

  visited[a][b] = true;
    cont++;

  dfs(mat, a - 1, b -1);
  dfs(mat, a - 1, b);
  dfs(mat, a -1, b + 1);
  dfs(mat, a, b + 1);
  dfs(mat, a + 1, b + 1);
  dfs(mat, a + 1, b);
  dfs(mat, a + 1, b - 1);
  dfs(mat, a, b -1);
}

int main() {
  int t, a, b;
  string aux;
  cin >> t;
  getline(cin, aux);
  getline(cin, aux);
  for (int z=0; z<t; z++) {
    vs matrix;
    while (getline(cin, aux) && aux != "") {
      if (aux[0] == 'L' || aux[0] == 'W') {
        matrix.push_back(aux);
      } else {
        stringstream ss(aux);
        ss >> a >> b;
        cont = 0;
        clean();

        dfs(matrix, --a, --b);
        cout << cont << "\n";

      }
    }
    if(z < t - 1) cout << '\n';
  }
  return 0;
}
