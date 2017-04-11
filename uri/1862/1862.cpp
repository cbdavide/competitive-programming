#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

int vertex, edges;

void dfs(vb &visited, vvi &graph, int s) {
    visited[s] = true;
    vertex += 1;
    edges += graph[s].size();
    for(int v : graph[s]) {
        if(!visited[v])
            dfs(visited, graph, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    char c;
    cin >> v;
    vvi graph(v);
    vb visited(v);
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++) {
            cin >> c;
            if(i != j && c == 'S')
                graph[i].push_back(j);
        }
    }

    vi componts;
    for(int i=0; i<v; i++) {
        if(!visited[i]) {//Component
            vertex = edges = 0;
            dfs(visited, graph, i);
            if((vertex * (vertex - 1) != edges)) {
                cout << "-1\n";
                return 0;
            }
            componts.push_back(vertex);
        }
    }
    sort(componts.rbegin(), componts.rend());
    cout << componts.size() << '\n';
    for(int i=0; i<componts.size(); i++) {
        cout << componts[i];
        if(i < componts.size() - 1) cout << ' ';
    }
    cout << endl;
    return 0;
}
