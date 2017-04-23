#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;

int pr(int node, int size, int balls) {
    int left = node << 1; int right = node << 1 | 1;
    if(left < size && right < size) {
        if(balls % 2) return pr(left, size, balls / 2 + 1);
        else return pr(right, size, balls / 2);
    }
    return node;
}

int main() {
    int t, d, l, idx, size;
    cin >> t;
    while(t--) {
        cin >> d >> l;
        size = pow(2, d);
        cout << pr(1, size, l) << '\n';
    }
    cin >> t;
    return 0;
}
