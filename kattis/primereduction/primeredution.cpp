#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n){
    long long root = sqrt(n);

    if(n % 2 == 0)
        return n == 2;
    if(n % 3 == 0)
        return n == 3;

    for(int i=5; i <= root; i += 6) {
        if(n % i == 0 || n % (i+2) == 0)
            return false;
    }

    return true;
}

long long find_next_prime(long long n) {

    if(n == 2) {
        return 3;
    }

    n += 2;
    while(!is_prime(n))
        n += 2;

    return n;
}

int prime_reduction(long long n) {
    long long prime;
    int x = 0;

    while(n != 1 ) {
        prime = 2;
        while(n % prime != 0) // Find the prime
            prime = find_next_prime(prime);

        n /= prime;
        x += prime;
    }
    return x;
}

main() {
    long long n, cont;

    while(cin >> n && n != 4) {
        cont = 1;

        while(!is_prime(n)) {
            n = prime_reduction(n);
            cont++;
        }

        cout << n << ' ' << cont << '\n';
    }
}
