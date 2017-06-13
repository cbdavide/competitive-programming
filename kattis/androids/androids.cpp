#include <bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n, 1)) {
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
        return true;
    }
};

int mst(int V, viii &E) {
    int answ = 0, x, y;
    union_find uf(V);
    sort(E.begin(), E.end());
    for(int i=0; i<E.size(); i++) {
        x = E[i].second.first;
        y = E[i].second.second;
        if(uf.unite(x, y)) answ += E[i].first;
    }
    return answ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    int mat[n][3];
    viii edges;
    for(int i=0; i<n; i++)
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            m = min(abs(mat[i][0] - mat[j][0]), abs(mat[i][1] - mat[j][1]));
            m = min(m, abs(mat[i][2] - mat[j][2]));
            edges.push_back(iii(m, ii(i, j)));
        }
    }
    cout << mst(n, edges) << '\n';
}
