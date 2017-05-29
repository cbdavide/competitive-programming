#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef map<char, vc> mcvc;
typedef map<char, bool> mcb;

int k;
mcvc adj; mcb vis;

int dfs(char p, char s, int cont) {
    vis[s] = !(cont % k);
    for(int v=0; v<adj[s].size(); v++) {
        if(!vis[adj[s][v]] && adj[s][v] != p) {
            if(vis[s]) cout << s << ' ';
            return dfs(s, adj[s][v], cont  + 1);
        }
    }
    cout << '/' << s << '\n';
    return 0;
}

void resolve() {
    char gr, M, T;
    cin >> M >> T >> k;
    gr = dfs(T, M, 1);
    adj.clear(); vis.clear();
}

int main() {
    char root, gr, rel;

    while(cin >> root) {
        if(root == '#') break;
        else {
            cin >> gr;
            if(gr == ';') continue;
            if(gr == '.')  {
                resolve();
                continue;
            }
            while(cin >> rel && rel != ';' && rel != '.') {
                adj[root].push_back(rel);
            }
            if(rel == '.') {
                resolve();
            }
        }
    }
    return 0;
}
