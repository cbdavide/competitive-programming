#include <bits/stdc++.h>
using namespace std;

typedef stack<string> s_stack;
typedef vector<string> vs;
map<string, vs> adj;
map<string, bool> vis;
s_stack sorted;

void dfs(string s) {
    vis[s] = true;
    for(string v : adj[s]) {
        if(!vis[v]) dfs(v);
    }
    sorted.push(s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string line, a, b;
    cin >> n;
    getline(cin, line);
    while(n--) {
        getline(cin, line);
        stringstream ss(line);
        ss >> a; a.pop_back();
        while(ss >> b)
            adj[b].push_back(a);
    }
    getline(cin, line);
    dfs(line);
    while(!sorted.empty()) {
        cout << sorted.top() << '\n';
        sorted.pop();
    }
    return 0;
}
