#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, l, r, cont;
    cin >> t;
    for(int z=1; z<=t; z++) {
        cin >> l >> r;
        cont = 0;
        for(int i=l; i<=r; i++)
            if(i % 2 != 0) cont += i;
        cout << "Case " << z << ": " << cont << '\n';
    }
    return 0;
}
