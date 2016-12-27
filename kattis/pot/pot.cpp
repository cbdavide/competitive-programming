#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    unsigned int cont = 0, temp;
    int t, pot;
    string num;

    cin >> t;
    while(t--) {
        cin >> num;

        pot = num.back() - '0';
        num.pop_back();
        temp = stoi(num);

        cont += pow(temp, pot);

    }
    cout << cont << '\n';

    return 0;
}
