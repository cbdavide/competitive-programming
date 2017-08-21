#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b) {
    return (b + (a % b)) % b;
}

int main() {
    int n, c, s, a, t, cont;
    while(cin >> n >> c >> s) {
        if(s == n) s = 0;
        a = 1; cont = s == 1;
        for(int i=0; i<c; i++) {
            cin >> t;
            a = mod(a + t, n);
            if(a == s) cont++;
        }
        cout << cont << '\n';
    }
    return 0;
}
