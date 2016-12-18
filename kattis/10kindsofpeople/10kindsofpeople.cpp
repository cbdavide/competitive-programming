#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef int** matrix;
typedef bool** memory;

typedef vector<memory> vmemory;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char mat[1001][1001];

memory init_memory(pii size) {
    memory m = new bool*[size.first];

    for(int i=0; i<size.first; i++) {

        m[i] = new bool[size.second];
        for(int j=0; j<size.second; j++)
            m[i][j] = 0;
    }

    return m;
}

memory bfs(pii size, pii a, pii b, char type) {
    const int ROW = size.first;
    const int COL = size.second;

    memory m = init_memory(size);

    queue<pii> q;
    m[a.first][a.second] = 1;

    q.push(pii(a.first, a.second));

    while(!q.empty()) {
        pii actual = q.front();
        q.pop();

        for(int i=0; i<4; i++) {
            int x = actual.first + dir[i][0];
            int y = actual.second + dir[i][1];

            if(x >= 0 && x < ROW && y >= 0 && y < COL && mat[x][y] == type && !m[x][y]) {
                m[x][y] = 1;
                q.push(pii(x, y));
            }
        }
    }
    return m;
}

memory find_memory(vmemory arr, pii pos) {
    for(int i=0; i<arr.size(); i++) {
        if(arr[i][pos.first][pos.second])
            return arr[i];
    }
    return NULL;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, n;
    int x1, y1, x2, y2;
    bool val;
    string answ;

    memory conex_graph;
    map<char, vmemory> graphs;

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cin >> mat[i][j];
    }

    cin >> n;
    while(n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; x2--; y1--; y2--;

        pii from(x1, y1);
        pii to(x2, y2);

        if(mat[x1][y1] == mat[x2][y2]) {
            //The magic happens here
            char type = mat[x1][y1];
            conex_graph = find_memory(graphs[type], from);

            if(conex_graph == NULL) {
                conex_graph = bfs(pii(r, c), from, to, type);
                graphs[type].push_back(conex_graph);
            }

            val = conex_graph[to.first][to.second];

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
