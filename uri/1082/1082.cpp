#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef set<int> vi;
typedef vector <vi> vvi;

void dfs(vb &visited, vi &answ, vvi &graph, int s) {
    visited[s] = true;
    answ.insert(s);
    for(auto v : graph[s]) {
        if(!visited[v])
            dfs(visited, answ, graph, v);
    }
}

int main() {
    int t, v, e, x, y, cont;
    char a, b;
    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> v >> e;
        vvi graph(v);
        vb visited(v, 0);
        for(int j=0; j<e; j++) {
            cin >> a >> b;
            x = (int)a - 97; y = (int)b - 97;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        cont = 0;
        printf("Case #%d:\n", i);
        for(int j=0; j<graph.size(); j++) {
            if(!visited[j]) {
                cont++;
                vi component;
                dfs(visited, component, graph, j);
                for(int item : component)
                    printf("%c,", (char)item + 97);
                printf("\n");
            }
        }
        printf("%d connected components\n\n", cont);
    }
    return 0;
}
