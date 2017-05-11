#include <iostream>
#include <map>
using namespace std;

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char c[4] = {'N', 'E', 'S', 'W'};

map<char, int> mapper;

int main() {

    mapper['N'] = 0;
    mapper['E'] = 1;
    mapper['S'] = 2;
    mapper['W'] = 3;

    int n, m, x, y;
    char orientation;
    string trail;

    cin >> n >> m;
    char mat[n][m];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
            mat[i][j] = ' ';
    }

    int xx, yy, direc;
    bool cond;
    while(cin >> x >> y >> orientation) {
        direc = mapper[orientation];
        cin >> trail;
        xx = yy = 0;
        cond = false;
        for(int i=0; i<trail.size(); i++) {
            if(trail[i] == 'F') {
                xx = dir[direc][0];
                yy = dir[direc][1];

                if(x + xx == -1 || x + xx == n + 1 || y + yy == -1 || y + yy == m + 1) {
                    if(mat[x][y] != '*') {
                        mat[x][y] = '*';
                        cond = true;
                        break;
                    }
                } else {
                    x += xx;
                    y += yy;
                }

            }else if(trail[i] == 'R') {
                direc = (direc + 1) % 4;
            }else {
                direc = (direc + 3) % 4;
            }
        }
        cout << x << ' ' << y << ' ';
        if(cond) cout << c[direc] << " LOST\n";
        else cout << c[direc] << '\n';
    }

    return 0;
}
