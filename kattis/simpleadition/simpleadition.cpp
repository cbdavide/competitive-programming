#include <iostream>
#include <string>
using namespace std;

int add(char n1, char n2) {
    return (n1 - 48 ) + (n2 - 48);
}

main() {

    string n1, n2, result;
    cin >> n1 >> n2;
    int carry = 0 , i, j, aux2;

    i = n1.size()-1;
    j = n2.size()-1;

    for(; i>=0 || j>=0; i--, j--){
        if(j < 0) {
            aux2 = add(n1[i], '0');
        } else if (i < 0) {
            aux2 = add(n2[j], '0');
        } else {
            aux2 = add(n1[i], n2[j]);
        }
        aux2 += carry;
        if(aux2 > 9) {
            carry = 1;
            aux2 -= 10;
        } else {
            carry = 0;
        }

        result.insert(0, to_string(aux2));
    }
    if(carry)
        result.insert(0, to_string(1));

    cout << result << '\n';
}
