#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

string separator(int n) {
    string answ = "+";
    for(int i=0; i<n*2 - 1; i++)
        answ.push_back('-');
    answ.push_back('+');
    return answ;
}

void bfs(bool visited[], vvi &graph, int x) {
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : graph[u]) {
            if(!visited[v]) {
                if(v == x) continue;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void printr(bool visited[], int v, string sepi) {
    printf("%c", '|');
    for(int l=0; l<v; l++)
        printf("%c|", visited[l] ? 'Y' : 'N');
    cout << "\n" << sepi << "\n";
}

int main() {
    int t, v, val;
    string sepi;
    scanf("%d", &t);
    for(int i=1; i<=t; i++) {
        scanf("%d", &v);

        vvi graph(v);
        bool visited[v][v];
        memset(visited, 0, v * v);

        for(int j=0; j<v; j++) {
            for(int k=0; k<v; k++) {
                scanf("%d", &val);
                if(val) graph[j].push_back(k);
            }
        }
        sepi = separator(v);
        bfs(visited[0], graph, 0);
        printf("Case %d:\n" , i);
        cout << sepi << "\n|";
        for(int l=0; l<v; l++)
            printf("%c|", visited[0][l] ? 'Y' : 'N');
        cout << "\n" << sepi << "\n";

        for(int l=1; l<v; l++) {
            printf("|");
            bfs(visited[l], graph, l);
            for(int m=0; m<v; m++) {
                if(visited[0][m] && (m == l || !visited[l][m]))
                    printf("%c|", 'Y');
                else
                    printf("%c|", 'N');
            }
            cout << '\n' << sepi << '\n';
        }
    }
    return 0;
}
