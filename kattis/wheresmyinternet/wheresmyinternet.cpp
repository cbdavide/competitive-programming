#include <iostream>
#include <vector>
using namespace std;

struct union_find {
    vector<int> parent;

    union_find(int n) {
        parent = vector<int>(n + 1);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x)
            return x;

        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    int n, q, a, b;
    bool cond = 0;;
    cin >> n >> q;

    union_find set = union_find(n);

    for(int i=0; i<q; i++) {
        cin >> a >> b;
        set.unite(a, b);
    }

    for(int i=1; i<set.parent.size(); i++) {
        if(set.find(i) != set.find(1)) {
            cout << i << '\n';
            cond = 1;
        }
    }

    if(!cond)
        cout << "Connected\n";

    return 0;
}
