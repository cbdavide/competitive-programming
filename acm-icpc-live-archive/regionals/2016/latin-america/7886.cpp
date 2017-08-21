#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    while(cin >> a >> b >> c >> d) {
        int mini = 1e9;
        mini = min(mini, abs((a + b) - (c + d)));
        mini = min(mini, abs((a + c) - (b + d)));
        mini = min(mini, abs((a + d) - (b + c)));

        cout << mini << '\n';
    }
    return 0;
}
