#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        if(n == 0 || m == 0 || m == 1 || n < m) {
            cout << "Boring!\n";
            continue;
        }

        vector<int> answ; answ.push_back(n);
        while(n % m == 0 && n != 1) {
            answ.push_back(n / m);
            n /= m;
        }
        if(n == 1) {
            for(int i=0; i<answ.size(); i++) {
                cout << answ[i];
                if(i < (int)answ.size() - 1)
                    cout << ' ';
            } cout << '\n';
        } else
            cout << "Boring!\n";
    }
    return 0;
}
