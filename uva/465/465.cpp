#include <bits/stdc++.h>
using namespace std;

main() {
    int limit = numeric_limits<int>::max();

    char a[1000], b[1000];
    double na, nb, nr;
    char c;

    while(cin >> a >> c >> b) {
        na = atof(a);
        nb = atof(b);

        cout << a << " " << c << " " << b << '\n';
        if(na > limit)
            cout << "first number too big\n";

        if(nb > limit)
            cout << "second number too big\n";

        if(c == '+')
            nr = na + nb;
        else
            nr = na * nb;

        if(nr > limit)
            cout << "result too big\n";

    }
}
