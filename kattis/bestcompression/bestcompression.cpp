#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ll a, b;
    cin >> a >> b;

    if(a <= ((1LL << (b + 1)) - 1)) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}
