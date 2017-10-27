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

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

typedef vector<string> vs;
typedef map<string, vs> msvs;
typedef map<string, bool> msb;
typedef map<string, int> msi;

bool check(string &a, string &b) {
    if(size(a) != size(b)) return false;
    int cont = 0;
    rep(i, 0, size(a)) if(a[i] == b[i]) cont++;
    return (size(a) - cont) == 1;
}

void bfs(msvs &G, msb &vis, msi &dist, string s, string tgt) {
    queue<string> q;
    vis[s] = true;
    q.push(s);
    while(!q.empty()) {
        string cur = q.front(); q.pop();
        for(string v : G[cur]) {
            if(!vis[v]) {
                vis[v] = true;
                dist[v] = dist[cur] + 1;
                q.push(v);
            }
            if(v == tgt) return;
        }
    }
}

int main() {
    string u, v, line;
    int t; cin >> t;
    for(int z=1; z<=t; z++) {
        if(z > 1) cout << endl;

        vs tmp; msvs G;
        while(cin >> u && u != "*")
            tmp.PB(u);
        rep(i, 0, size(tmp)) {
            rep(j, i + 1, size(tmp)) {
                if(check(tmp[i], tmp[j])) {
                    G[tmp[i]].PB(tmp[j]);
                    G[tmp[j]].PB(tmp[i]);
                }
            }
        }
        getline(cin, line);
        while(getline(cin, line) && line != "") {
            stringstream ss(line);
            ss >> u >> v;
            msb vis; msi dist;
            bfs(G, vis, dist, u, v);
            cout << u << ' ' << v << ' ' << dist[v] << endl;
        }

    }
    return 0;
}