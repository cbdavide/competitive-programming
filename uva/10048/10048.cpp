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
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n)) {
        rep(i, 0, n) data[i] = i;
    }
    int find(int x) {
        if(x == data[x]) return x;
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

vvii mst(int V, viii &E) {
    vvii G(V);
    union_find uf(V);
    sort(E.begin(), E.end());
    iter(it, E) {
        int x = (*it).S.F;
        int y = (*it).S.S;
        if(uf.unite(x, y)) {
            G[x].push_back(ii(y, (*it).F));
            G[y].push_back(ii(x, (*it).F));
        }
    }
    return G;
}

void dfs(vvii &G, vb &vis, vii &pi, int s, int t) {
    vis[s] = true;
    iter(it, G[s]) {
        int v = (*it).F;
        if(!vis[v]) {
            pi[v] = ii(s, (*it).S);
            if(v == t) {vis[v] = true; return;}
            dfs(G, vis, pi, v, t);
        }
    }
}

int main() {
    int V, E, Q, u, v, w, z = 1;
    while(cin >> V >> E >> Q && (V + E + Q)){
        if(z > 1) cout << endl;
        
        viii list(E);
        rep(i, 0, E) {
            cin >> u >> v >> w;
            list[i] = iii(w, ii(u, v));
        }
        printf("Case #%d\n", z++);
        vvii G = mst(++V, list);
        rep(i, 0, Q) {
            cin >> u >> v;
            vb vis(size(G)); vii PI(size(G));
            dfs(G, vis, PI, u, v);
            if(vis[v]) {
                int maxi = -INF;
                while(PI[v].F != 0) {
                    maxi = max(maxi, PI[v].S);
                    v = PI[v].F;
                
                }
                cout << maxi << endl;            
            } else {
                cout << "no path" << endl;
            }
            
        }
    }
    return 0;
}