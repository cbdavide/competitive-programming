#include <bits/stdc++.h>
using namespace std;

main() {
    int values[] = {0, 1, 2, 5, 9, 8, 6};
    int n;
    string answ;

    while(cin >> n) {
        answ = "";
        while(n) {
            answ += to_string(values[n%7]);
            n = n/7;
        }
        cout << answ << '\n';
    }
}
