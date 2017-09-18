#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

typedef pair<double, double> dd;
typedef vector<dd> vdd;

int max_flow(int n, int s, int t, int **arr)  {
    int *back = new int[n], cur, flow = 0;
    while(true) {
        for(int i=0; i<n; i++) back[i] = -1;
        queue<int> Q;
        Q.push(back[s] = s);
        while(!Q.empty()) {
            cur = Q.front(); Q.pop();
            if(cur == t) break;
            for(int i=0; i<n; i++) {
                if(arr[cur][i] > 0 && back[i] < 0) {
                    back[i] = cur;
                    Q.push(i);
                }
            }
        }
        if(back[t] < 0) break;
        int cap = INF; cur = t;
        while(cur != s) {
            cap = min(cap, arr[back[cur]][cur]);
            cur = back[cur];
        }
        assert(cap > 0 && cap < INF);
        cur = t;
        while(cur != s) {
            arr[back[cur]][cur] -= cap;
            arr[cur][back[cur]] += cap;
            cur = back[cur];
        }
        flow += cap;
    }
    delete[] back;
    return flow;
}

bool check(dd &i, dd &j, int dist) {
    double xx = pow(j.first - i.first, 2.0);
    double yy = pow(j.second - i.second, 2.0);

    return sqrt(xx + yy) <= dist;
}

int main() {
    int n, m, s, v, size = 204;
    double x, y;
    while(cin >> n >> m >> s >> v) {

        int **G = new int*[size];
        for(int i=0; i<size; i++) {
            G[i] = new int[size];
            for(int j=0; j<size; j++)
                G[i][j] = 0;
        }

        int dist = s * v;
        vdd g(n), h(m);

        for(int i=0; i<n; i++) {
            cin >> x >> y;
            g[i] = dd(x, y);
        }

        for(int i=0; i<m; i++) {
            cin >> x >> y;
            h[i] = dd(x, y);
        }

        for(int i=1; i<=n; i++)
            G[0][i] = 1;

        for(int j=1; j<=m; j++)
            G[j + 100][202] = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {

                if(check(g[i], h[j], dist)) {
                    G[i + 1][j + 101] = 1;
                }

            }
        }
        cout << (n - max_flow(size, 0, 202, G)) << '\n';
    }
    return 0;
}
