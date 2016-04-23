#include <bits/stdc++.h>
using namespace std;

main() {
    string number;
    int total, expo;
    while(cin >> number && number != "0") {
        total = 0;
        expo = number.size();

        for(int i=0; i<number.size(); i++) {
            total += (number[i] - 48) * (pow(2, expo--) - 1);
        }

        cout << total << '\n';
    }
}
