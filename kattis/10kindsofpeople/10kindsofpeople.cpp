#include <bits/stdc++.h>
using namespace std;

#define INF_MAX 2147483647

typedef pair<int, int> pii;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char mat[1001][1001];
int paths[1001][1001];

struct node {
    int x;
    int y;
    int level;

    node(int r, int c, int l) {
        x = r;
        y = c;
        level = l;
    };
};

void reset_paths(pii size) {
    for(int i=0; i<size.first; i++) {
        for(int j=0; j<size.second; j++)
            paths[i][j] = INF_MAX;
    }
}

bool bfs(pii size, pii a, pii b, char type) {
    const int ROW = size.first;
    const int COL = size.second;

    queue<node> q;
    paths[a.first][a.second] = 0;

    q.push(node(a.first, a.second, 0));

    while(!q.empty()) {
        struct node actual = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int x = actual.x + dir[i][0];
            int y = actual.y + dir[i][1];

            if(x >= 0 && x < ROW && y >= 0 && y < COL && mat[x][y] == type && paths[x][y] == INF_MAX) {
                paths[x][y] = actual.level + 1;
                q.push(node(x, y, actual.level + 1));
            }
        }
    }

    return paths[b.first][b.second] != INF_MAX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int r, c, n;
    int x1, y1, x2, y2;
    bool val;
    string answ;

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> mat[i][j];
            paths[i][j] = INF_MAX;
        }
    }

    cin >> n;
    while(n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--; y1--; y2--;

        pii from(x1, y1);
        pii to(x2, y2);

        if(mat[x1][y1] == mat[x2][y2]) {
             val = bfs(pii(r, c),from, to, mat[x1][y1]);
             reset_paths(pii(r, c));
        } else {
            val = false;
        }

        if(val)
            answ = mat[x1][y1] == '1' ? "decimal" : "binary";
        else
            answ = "neither";

        cout << answ << '\n';
    }

    return 0;
}
