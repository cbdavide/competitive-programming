#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, max, total;
    cin >> t;
    while(t--) {
        max = 0;
        total = 0;
        cin >> n;
        vector<int> c(n);
        for(int i=0; i<n; i++) {
            cin >> c[i];
            total += c[i];

            if(c[i] > c[max])
                max = i;
        }

        int winner = c[max];
        sort(c.rbegin(), c.rend());

        if(c[0] == c[1])
            cout << "no winner\n";
        else if(winner > total / 2)
            cout << "majority winner " << max + 1 << '\n';
        else
            cout << "minority winner " << max + 1 << '\n';
    }
    return 0;
}
