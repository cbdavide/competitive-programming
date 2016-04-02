#include <bits/stdc++.h>
using namespace std;

int toInt(char c) {
    return c - '0';
}

string insertPadding(string num, int padding) {
    string answ = num;
    for(int i=0; i<padding; i++) {
        answ += "0";
    }
    return answ;
}

string add(string num1, string num2) {
    string answ = "";
    int carry = 0, result;
    for(int i=num1.size()-1, j=num2.size()-1; i>=0; i--, j--) {

        if(j < 0)
            result = toInt(num1[i]) + carry;
        else
            result = toInt(num1[i]) + toInt(num2[j]) + carry;

        if(result > 9) {
            carry = 1;
            result -= 10;
        } else {
            carry = 0;
        }

        answ.insert(0, to_string(result));
    }
    if(carry != 0)
        answ.insert(0, "1");

    return answ;
}

string product(string num1, int num2) {
    string answ, temp;
    int carry = 0, result;

    for(int i=num1.size()-1; i>=0; i--) {
        result = (toInt(num1[i]) * num2) + carry;
        if(result > 9) {
            temp = to_string(result);
            carry = toInt(temp[0]);
            result = toInt(temp[1]);
        } else {
            carry = 0;
        }
        answ.insert(0, to_string(result));
    }
    if(carry != 0)
        answ.insert(0, to_string(carry));
    return answ;
}

main() {
    string n1, n2, aux, answ;

    while(cin >> n1 >> n2) {
        answ = "0";

        if(n1.size() < n2.size()) {//n2 is bigger
            aux = n1;
            n1 = n2;
            n2 = aux;
        }

        for(int i=n2.size()-1, j=0; i>=0; i--, j++) {
            if(n2 != "0")
                aux = product(n1, toInt(n2[i]));
            else
                aux = "0";

            aux = insertPadding(aux, j);

            if(aux.size() >= answ.size())
                answ = add(aux, answ);
            else
                answ = add(answ, aux);
        }
        cout << answ << endl;
    }
}
