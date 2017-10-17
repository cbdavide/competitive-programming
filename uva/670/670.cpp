#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T &x) {return x.size();}
template <class T> T mod(T a, T b) { return (b + (a % b)) % b;}

#define F first
#define S second
#define INF 1e9

typedef pair<int, int> ii;
typedef pair<ii, ii> edge;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<edge> vedge;

int sqrdist(ii &a, ii &b) {
    return pow(b.F - a.F, 2) + pow(b.S - a.S, 2);
}

bool check(edge &e,ii &c) {
    double bob = sqrt(sqrdist(e.F, e.S));
    double ralph = sqrt(sqrdist(e.F, c)) + sqrt(sqrdist(c, e.S));
    return ralph <= 2 * bob;
}

int max_flow(int n, int s, int t, int **arr) {
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
    delete [] back;
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x, y, bn, cn, t;
    bool cond = false;

    cin >> t;
    while(t--) {

        if(cond) cout << '\n';

        cond = true;
        cin >> bn >> cn;

        vedge edges(bn - 1); 
        vii points(cn), temp(bn);
        int S = bn + cn + 2;

        int **G = new int*[S];
        for(int i=0; i<S; i++) {
            G[i] = new int[S];
            for(int j=0; j<S; j++)
                G[i][j] = 0;
        }

        for(int i=0; i<bn; i++) {
            cin >> x >> y;
            temp[i] = ii(x, y);
        }

        for(int i=0; i<bn-1; i++) {
            edges[i] = edge(temp[i], temp[i + 1]);
        }

        for(int i=0; i<cn; i++) {
            cin >> x >> y;
            points[i] = ii(x, y);
        }

        for(int i=0; i<size(edges); i++) {
            for(int j=0; j<size(points); j++) {

                if(check(edges[i], points[j]))
                    G[i + 1][j + bn ] = 1;
                
            }
        }

        for(int i=1; i<=size(edges); i++)
            G[0][i] = 1;
        for(int i=0; i<cn; i++)
            G[i + bn ][S - 1] = 1;

        cout << max_flow(S, 0, S - 1, G) + bn << '\n';

        for(int i=1; i<=bn-1; i++) {
            cout << edges[i - 1].F.F << ' ' << edges[i - 1].F.S << ' ';
            if(!G[0][i]) {
                for(int j=bn; j<S-1; j++) {
                    if(G[j][i]) {
                        cout << points[j - bn].F << ' ' << points[j - bn].S << ' ';
                        break;
                    }
                }
            }
        }
        cout << edges.back().S.F << ' ' << edges.back().S.S << '\n';
    }
    return 0;
}
