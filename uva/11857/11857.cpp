#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T &x) {return x.size();}
template <class T> T mod(T a, T b) { return (b + (a % b)) % b;}

#define F first
#define S second
#define PB push_back
#define endl '\n'
#define rep(i, a, b) for(__typeof(a) i=a; i<(b); i++)
#define iter(it, c) for(__typeof((c).begin()) it=(c).begin(); \
 it != (c).end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef set<int> si;

typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<bool> vb;

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n)) {
        rep(i, 0, size(data)) data[i] = i;
    }
    int find(int x) {
        if(data[x] == x) return x;
        data[x] = find(data[x]);
        return data[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        if(pe[px] > pe[py]) swap(px, py);
        pe[px] += pe[py];
        data[py] = px;
        return true;
    }
};

int mst(viii &E, int V) {
    vb vis(V);
    int maxi = -INF, vertex = 0;
    union_find uf(V);
    sort(E.begin(), E.end());
    iter(it, E) {
        int x = (*it).S.F;
        int y = (*it).S.S;
        if(uf.unite(x, y)) {
            if(!vis[x]) {
                vertex++;
                vis[x] = true;
            }
            if(!vis[y]) {
                vertex++;
                vis[y] = true;
            }
            maxi = max(maxi, (*it).F);
        }
    }
    return (vertex == V) ? maxi : -INF;
}

int main() {
    int V, E, u, v, w, answ;
    while(cin >> V >> E && (V + E)) {
        viii list(E);
        rep(i, 0, E) {
            cin >> u >> v >> w;
            list[i] = iii(w, ii(u, v));
        }
        answ = mst(list, V);
        if(answ == -INF)
            cout << "IMPOSSIBLE" << endl;
        else cout << answ << endl;
    }
    return 0;
}