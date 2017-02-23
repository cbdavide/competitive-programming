#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<long long> vi;

int main() {
    int t, n;
    long long proc;
    cin >> t;
    for(int j=1; j<=t; j++) {
        proc = 0;
        cin >> n;
        vi a(n), b(n);

        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        for(int i=0; i<n; i++)
            proc += a[i] * b[i];

        cout << "Case #" << j << ": " << proc << '\n';
    }
    return 0;
}
