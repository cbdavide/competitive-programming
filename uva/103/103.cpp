#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T &x) {return x.size();}
template <class T> T mod(T a, T b) { return (b + (a % b)) % b;}

#define F first
#define S second
#define endl '\n'
#define rep(i, a, b) for(__typeof(a) i=a; i<(b); i++)
#define iter(it, c) for(__typeof((c).begin()) it=(c).begin(); \
 it != (c).end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;
typedef set<int> si;

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

vi top, vis;

bool check(vi &a, vi &b) {
    rep(i, 0, size(a)) {
        if(a[i] >= b[i])
            return false;
    }
    return true;
}

void topsort(vvii &G, int s) {
    vis[s] = true;
    rep(i, 0, size(G[s])) {
        int v = G[s][i].F;
        if(!vis[v])
            topsort(G, v);
    }
    top.push_back(s);
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        vvi boxes(n);
        rep(i, 0, n) {
            boxes[i] = vi(m);
            rep(j, 0, m)
                cin >> boxes[i][j];
            sort(boxes[i].begin(), boxes[i].end());
        }
        vvii G(n + 2);
        rep(i, 1, n + 1) {
            G[0].push_back(ii(i, 0));
            G[i].push_back(ii(n + 1, 0));
        }
        rep(i, 1, n + 1) {
            rep(j, 1, n + 1) {
                if(i != j && check(boxes[i-1], boxes[j-1])){
                    G[i].push_back(ii(j, -1));                
                }
            }
        }

        top.clear(); vis.assign(n + 2, 0);
        topsort(G, 0);

        reverse(top.begin(), top.end());
        vi dist(n + 2, INF), parent(n + 2, -1);
        dist[0] = 0;

        rep(i, 0, size(top)) {
            int u = top[i];
            rep(j, 0, size(G[u])) {
                ii v = G[u][j];
                if(dist[v.F] > dist[u] + v.S) {
                    dist[v.F] = dist[u] + v.S;
                    parent[v.F] = u;
                }
            }
        } 
        int k = n + 1;
        vi answ;
        while(parent[k] != 0) {
            answ.push_back(parent[k]);
            k = parent[k];
        }
        cout << answ.size() << endl; 
        reverse(answ.begin(), answ.end());
        rep(i, 0, size(answ)) {
            cout << answ[i];
            if(i < size(answ) - 1)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}