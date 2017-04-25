#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator vitr;

int main() {
    int t, n, cont, first, last, difference;
    vitr j;
    while(cin >> t) {
        cin >> n;
        vi popes(n);
        for(int i=0; i<popes.size(); i++)
            cin >> popes[i];

        cont = -1; first = last = 0;
        for(vitr i=popes.begin(); i!=popes.end(); i++) {
            j = upper_bound(popes.begin(), popes.end(), *i + t - 1);
            difference = (j - popes.begin()) - (i - popes.begin());
            if(difference > cont) {
                cont = difference;
                first = *i;
                last = *(--j);
            }
        }
        cout << cont << ' ' << first << ' ' << last << '\n';
    }
    return 0;
}
