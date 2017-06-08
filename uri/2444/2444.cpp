#include <bits/stdc++.h>
using namespace std;

int main() {
    int ini, t, u;
    cin >> ini >> t;
    for(int i=0; i<t; i++) {
        cin >> u;
        if(ini + u > 100) ini = 100;
        else if(ini + u > 0) ini += u;
        else ini = 0;
    }
    cout << ini << '\n';
    return 0;
}
