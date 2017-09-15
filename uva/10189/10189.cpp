#include <bits/stdc++.h>
using namespace std;

int main() {
    int z = 1, n, m;
    while(cin >> n >> m && (n + m)) {
        if(z != 1) cout << '\n';
        char mat[n][m];
        int out[n][m];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == '*')
                    out[i][j] = -1;
                else out[i][j] = 0;
            }
        }
        cout << "Field #" << z++ << ":\n";
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == '*') {
                    if(i > 0 && j > 0  && mat[i - 1][j - 1] != '*')
                        out[i - 1][j - 1]++;
                    if(i > 0 && mat[i - 1][j] != '*')
                        out[i - 1][j]++;
                    if(j > 0 && mat[i][j - 1] != '*')
                        out[i][j - 1]++;
                    if(i < n - 1 && mat[i + 1][j] != '*')
                        out[i + 1][j]++;
                    if(j < m - 1 && mat[i][j + 1] != '*')
                        out[i][j + 1]++;
                    if(i < n - 1 && j < m - 1  && mat[i + 1][j + 1] != '*')
                        out[i + 1][j + 1]++;
                    if(i > 0 && j < m - 1  && mat[i - 1][j + 1] != '*')
                        out[i - 1][j + 1]++;
                    if(i < n - 1 && j > 0  && mat[i + 1][j - 1] != '*')
                        out[i + 1][j - 1]++;

                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == '*')
                    cout << '*';
                else cout << out[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
