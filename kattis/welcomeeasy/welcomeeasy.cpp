#include <bits/stdc++.h>
using namespace std;

typedef set<int> si;
typedef vector<int> vi;
typedef vector<si> vsi;
typedef map<char, vi> mcvi;

string TEMPLATE = "welcome to code jam";

mcvi build_table(string &line){
    mcvi T;
    for(int i=0; i<line.size(); i++) 
        T[line[i]].push_back(i);
    return T;
}

vsi build_graph(int size, mcvi &T) {
    vsi G(size);
    string tplt = TEMPLATE;

    for(int i=1; i<tplt.size(); i++) {
        for(int j : T[tplt[i]]) {
            //cout << j << ' ';
            for(int k : T[tplt[i - 1]]) {
                if(k > j) break;
                G[k].insert(j);
                // cout << k << " -> " << j << endl;
            }
        }
    }
    return G; 
}

int dfs(int source, int dst, string line, vsi &G) {
    if(dst == 18 && line[source] == TEMPLATE[18]) {
        return 1;
    } else if(dst == 18) return 0;

    int sum = 0;
    for(int v: G[source]) {
        if(TEMPLATE[dst + 1] != line[v])
            continue;
        sum = ((sum * 1LL) + dfs(v, dst + 1, line, G) % 10000);
    }
    return sum;
}

int main() {
    int t;
    string line;
    
    cin >> t;
    getline(cin, line);
    for(int z=1; z<=t; z++){
        getline(cin, line);
        mcvi table = build_table(line);
        vsi G = build_graph(line.size(), table);

        int sol = 0;
        for(int i : table['w'])
            sol += dfs(i, 0, line, G); 
        
        printf("Case #%d: %04d\n", z, sol);
    }
    return 0;
}
