#include <iostream>
#include <cmath>
using namespace std;

int next_power(int n) {
    int p = 0;
    while(pow(2, p) < n)
        p++;

    return pow(2, p);
}

int divs(int size, int k) {
    int t = 0, d = 0, p = 1;

    if(size == k)
        return 0;

    while(t != k) {

        if(t > k)
            t -= size / pow(2, p);
        else
            t += size / pow(2, p);

        d++;
        p++;
    }

    return d;
}

main() {
    int k, b;

    cin >> k;
    b = next_power(k);

    cout << b << " " << divs(b, k) << endl;
}
