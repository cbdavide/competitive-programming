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

typedef vector<vii> vvii;

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

int *dist;

struct cmp {
    bool operator()(int a, int b) {
        return dist[a] != dist[b] ? dist[a] < dist[b] : a < b;
    }
};

void dijkstra(vvii &G, int s, int t) {
    dist = new int[size(G)];
    rep(i, 0, size(G)) dist[i] = INF;
    set<int, cmp> pq;
    dist[s] = 0;
    pq.insert(s);
    while(!pq.empty()) {
        int curr = *pq.begin(); pq.erase(pq.begin());
        if(curr == t) return;
        iter(it, G[curr]) {
            int nxt = (*it).F, ndist = dist[curr] + (*it).S;
            if(ndist < dist[nxt]) pq.erase(nxt),
                dist[nxt] = ndist, pq.insert(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Z, V, E, u, s, t, v, w;
    cin >> Z;
    rep(z, 1, Z + 1) {
        cin >> V >> E >> s >> t;
        vvii G(V);
        rep(i, 0, E) {
            cin >> u >> v >> w;
            G[u].PB(ii(v, w));
            G[v].PB(ii(u, w));
        }
        dijkstra(G, s, t);
        if(dist[t] == INF)
            printf("Case #%d: unreachable\n", z);
        else
            printf("Case #%d: %d\n", z, dist[t]);            
    }
    return 0;
}