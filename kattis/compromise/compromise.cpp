#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;

        int A[m];
        memset(A, 0, sizeof A);
        
        string s;
        for(int i=0; i<n; i++) {
            cin >> s;
            for(int j=0; j<m; j++)
                A[j] += (s[j] == '1');
        }
        for(int i=0; i<m; i++)
            cout << (A[i] > (n / 2)) ? '1' : '0';
        cout << endl;
    }
    return 0;
}
