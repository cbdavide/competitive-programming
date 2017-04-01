#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef set<int> si;

map<char, int> mapa;

int mod(int a, int b) {
  return (a % b + b) % b;
}


int main() {
    int n, m, s;
    int inc[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    char a;
    string commands;

    mapa['N'] = 0; mapa['O'] = 3;  mapa['S'] = 2;  mapa['L'] = 1;

    while(cin >> n >> m >> s && (n + m + s)){
        char b[n][m];
        si cards;

        int x, y;
        char dir;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> a;
                b[i][j] = a;

                if(isupper(a)) {
                    dir = a;
                    x = i; y = j;
                }
            }
        }

        cin >> commands;
        int actual = mapa[dir], cont = 0;

        for(int i=0; i<commands.size(); i++) {
          if(commands[i] == 'D')
            actual++;
          else if(commands[i] == 'E')
            actual--;
          else if(commands[i] == 'F') {
            int xx = x + inc[mod(actual, 4)][0];
            int yy = y + inc[mod(actual, 4)][1];
            if(xx < n && xx >= 0 && yy < m && yy >=0) {
              if(b[xx][yy] != '#') {
                x = xx; y = yy;
                if(b[x][y] == '*') {
                  cont++;
                  b[x][y] = '-';
                }
              }
            }
          }
        }
        cout << cont << '\n';
    }

    return 0;
}
