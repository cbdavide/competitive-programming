#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, bool> mib;

int main() {
    int n, m, k;
    cin >> n >> m;
    vi A(n), T(n);
    mib seen;
    for(int i=0; i<n; i++) cin >> A[i];
    T[n - 1] = 1; seen[A[n - 1]] = true;
    for(int i=n-2; i>=0; i--) {
        T[i] = T[i + 1] + (seen[A[i]] ? 0 : 1);
        seen[A[i]] = true;
    }
    for(int i=0; i<m; i++) {
        cin >> k;
        cout << T[--k] << '\n';
    }
    return 0;
}
