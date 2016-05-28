#include <bits/stdc++.h>
using namespace std;

int main() {
    int cont = 0, root;
    long long n;
    cin >> n;

    while(n % 2 == 0) {
        n /= 2;
        cont++;
    }

    root = sqrt(n);
    for(int i=3; i<=root; i += 2) {
        while(n % i == 0) {
            n /= i;
            cont++;
        }
    }

    if(n > 2)
        cont++;

    cout << cont << '\n';
}
