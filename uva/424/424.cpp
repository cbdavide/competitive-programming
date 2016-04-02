#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
    string answ;
    int carry = 0, result;

    int i=s1.size()-1, j=s2.size()-1;
    for( ;i>=0; i--, j--) {

        if(j<0) {
            result = (s1[i] - '0') + carry;
            if(result > 9){
                carry = 1;
                result -= 10;
            } else {
                carry = 0;
            }

        } else {
            result = (s1[i] - '0') + (s2[j] - '0') + carry;
            if(result > 9) {
                carry = 1;
                result -= 10;
            } else {
                carry = 0;
            }
        }
        answ.insert(0, to_string(result));
    }

    if(carry)
        answ.insert(0, "1");

    return answ;
}

main() {
    string num1, num2, aux;
    while(cin >> num1 && num1 != "0") {
        if(num1.size() >= num2.size())
            num2 = add(num1, num2);
        else
            num2 = add(num2, num1);
    }
    cout << num2 << '\n';
}
