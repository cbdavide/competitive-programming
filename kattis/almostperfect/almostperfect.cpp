#include <bits/stdc++.h>
using namespace std;

int main() {
    int cont, root;
    long long n;

    while(cin >> n) {
        cont = 1;

        root = sqrt(n);
        for(int i=2; i<=root; i++) {//Finding all divisors
            if(n % i == 0 && i * i != n){
                cont += i;
                cont += n / i;
            } else if(n % i == 0 && i * i == n) {
                cont += i;
            }
        }

        if(n == cont)
            cout << n << " perfect\n";
        else if(abs(n - cont) <= 2)
            cout << n << " almost perfect\n";
        else
            cout << n << " not perfect\n";
    }
    return 0;
}
