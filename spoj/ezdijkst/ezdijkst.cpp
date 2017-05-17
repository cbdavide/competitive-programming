#include <bits/stdc++.h>
using namespace std;

#define INF 1e8

typedef pair<int, int> ii;
typedef vector<ii> vii;

int *dist;

struct cmp {
    bool operator()(int a, int b) {
        return dist[a] != dist[b] ? dist[a] < dist[b] : a < b;
    }
};

void dijkstra(int n, int s, int tgt, vii *adj) {
    dist = new int[n];
    for(int i=1; i<n; i++) dist[i] = INF;
    set<int, cmp> pq;
    dist[s] = 0;
    pq.insert(s);
    while(!pq.empty()) {
        int curr = *pq.begin(); pq.erase(pq.begin());
        for(int i=0; i<adj[curr].size(); i++) {
            int nxt = adj[curr][i].first,
                ndist = dist[curr] + adj[curr][i].second;
            if(ndist < dist[nxt]) pq.erase(nxt);
                dist[nxt] = ndist, pq.insert(nxt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, v, e, a, b, c, s, t;
    cin >> n;
    while(n--) {
        cin >> v >> e;
        vii *adj = new vii[v + 1];
        for(int i=0; i<e; i++) {
            cin >> a >> b >> c;
            adj[a].push_back(ii(b, c));
        }
        cin >> s >> t;
        dijkstra(v + 1, s, t, adj);
        if(dist[t] == INF) cout << "NO\n";
        else cout << dist[t] << '\n';
    }
    return 0;
}
