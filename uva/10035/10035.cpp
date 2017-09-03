#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    int carry, n_carry, num;

    while(cin >> a >> b && a != "0" || b != "0") {
        carry = n_carry = 0;

        for(int i=a.size()-1, j=b.size()-1; i>=0 || j>=0; i--, j--) {
            num = 0;
            if(i>=0)
                num += (a[i] - '0');
            if(j>=0)
                num += (b[j] - '0');

            num += carry;
            // cout << num << endl;

            if(num > 9) {
                carry = 1;
                num -= 10;
                n_carry++;
            } else {
                carry = 0;
            }
        }

        if(!n_carry) cout << "No ";
        else cout << n_carry << ' ';
        if(n_carry < 2)
            cout << "carry operation.\n";
        else
            cout << "carry operations.\n";
    }
    return 0;
}
