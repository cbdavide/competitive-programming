#include <bits/stdc++.h>
using namespace std;

#define MAX 1e5 + 7

typedef vector<int> vi;
typedef map<string, int> msi;

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n)) {
        for(int i=0; i<n; i++) data[i] = i;
    }
    int find(int x) {
        if(data[x] == x) return x;
        data[x] = find(data[x]);
        return data[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        if(pe[px] > pe[py]) swap(px, py);
        pe[px] += pe[py];
        data[py] = px;
        return px;
    }
};

int main() {
    string a, b;
    int cont = 0, id = 1;
    msi mapa; union_find uf(MAX);
    while(cin >> a >> b) {
        if(!mapa[a]) mapa[a] = id++;
        if(!mapa[b]) mapa[b] = id++;
        if(!uf.unite(mapa[a], mapa[b])) cont++;
    }
    cout << cont << '\n';
    return 0;
}
