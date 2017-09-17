#include <bits/stdc++.h>
using namespace std;

bool check(int n) {
    while(n % 2 == 0) n /= 2;
    while(n % 3 == 0) n /= 3;
    while(n % 5 == 0) n /= 5;
    return n == 1;
}

int main() {
    //Precomputation
    // int cont = 1, i = 2;
    // while(cont < 1500) {
    //     if(check(i))
    //         cout << ++cont << ": " << i << endl;
    //     i++;
    // }
    // cout << i - 1 << '\n';
    cout << "The 1500'th ugly number is 859963392.\n";
    return 0;
}
