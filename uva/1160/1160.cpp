#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct disjoint {
    vi data, pe;
    disjoint() : data(vi(1e5 + 1)), pe(vi(1e5 + 1, 0)) {
        for(int i=0; i<data.size(); i++)
            data[i] = i;
    }
    int find(int x) {
        if(x == data[x]) return x;
        data[x] = find(data[x]);
        return data[x];
    }
    bool unite(int i, int j) {
        int pi = find(i);
        int pj = find(j);
        if(pi == pj) return false;
        if(pe[pi] > pe[pj]) swap(pi, pj);
        pe[pi] += pe[pj];
        data[pj] = pi;
        return true;
    }
};

int main() {
    int a, b, answ = 0;
    disjoint *bombs = new disjoint();
    while(cin >> a) {
        if(a == -1) {
            cout << answ << '\n';
            bombs = new disjoint();
            answ = 0;
        }else {
            cin >> b;
            if(!bombs->unite(a, b))
                answ++;
        }
    }
    return 0;
}
