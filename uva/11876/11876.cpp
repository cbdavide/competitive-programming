#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator vitr;
vi dic(64729);

int nod(int n) {
    if(n <= 2) return n;
    int r = sqrt(n), cont = 0;
    for(int i=1; i<=r; i++) {
        if(n % i == 0) {
            if(i == n / i) cont++;
            else cont += 2;
        }
    }
    return cont;
}

int p(int n) {
    if(n == 0) return 1;
    if(dic[n]) return dic[n];
    int n1 = p(n - 1);
    dic[n] = n1 + nod(n1);
    return dic[n];
}

int main() {
    dic[0] = 1;
    p(64728);
    int t, a, b;
    vitr k, z;
    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> a >> b;
        k = lower_bound(dic.begin(), dic.end(), a);
        z = lower_bound(dic.begin(), dic.end(), b);
        if(*z != b) z--;
        a = k - dic.begin();
        b = z - dic.begin();
        printf("Case %d: %d\n", i, b - a + 1);
    }
    return 0;
}
