#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n, digit;
    bool cond = false;

    cin >> a >> b >> n;

    for(int i=0; i<10; i++) {
        if((a * 10 + i) % b == 0) {
            cond = true;
            digit = i;
            break;
        }
    }

    if(cond) {
        cout << a << digit;
        for(int i=1; i<n; i++)
            cout << '0';
        cout << endl;
    } else {
        cout << -1 << '\n';
    }

}
