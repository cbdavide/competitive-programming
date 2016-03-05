#include <bits/stdc++.h>
using namespace std;

int secuence(int a, int l) {
    int i=1;
    unsigned int limit = 2147483647;
    while(a != 1 && (a <= l && a <= limit)){
        if(a % 2 == 0)
            a /= 2;
        else
            a = 3*a + 1;

        if(a <= l && a <= limit)
            i++;
    }
    return i;
}

main() {
    
    int a, l, i=1;
    
    while((cin >> a && a >= 0) && (cin>> l && l >= 0)) {
        cout << "Case " << i << ": A = " << a <<
            ", limit = " << l << ", number of terms = " <<
            secuence(a, l) << endl;
        i++;
    }   
}