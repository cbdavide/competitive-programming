#include <bits/stdc++.h>
using namespace std;

int power(int x1, int x2) {
    return pow(x1 - x2, 2);
}

int d(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sqrt(power(x1, x2) + power(y1, y2) + power(z1, z2));
}

main() {
    int x, y, z, min, distance;
    vector<int> xt, yt, zt, answ(10, 0);

    while(cin >> x >> y >> z && (x || y || z)) {
        xt.push_back(x);
        yt.push_back(y);
        zt.push_back(z);
    }

    for(int i=0; i<xt.size(); i++) {
        min = 11;
        for(int j=0; j<xt.size(); j++) {
            if(i != j) {
                distance = d(xt[i], yt[i], zt[i], xt[j], yt[j], zt[j]);

                if(min > distance)
                min = distance;
            }
        }
        if(min < 10)
            answ[min] += 1;
    }
    for(int i=0; i<10; i++) {
        cout << setw(4) << answ[i];
    }
    cout << '\n';
}
