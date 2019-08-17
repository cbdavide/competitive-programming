#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, w;
    cin >> l >> w;

    if(w < l || (l*26) < w) {
        cout << "impossible" << endl;
        return 0;
    }

    int mod = w % l;
    vector<int> A(l, w / l);

    for(int i=0; (i<A.size()) && mod; i++) {
        if((mod + A[i]) > 26) {
            mod -= (26 - A[i]);
            A[i] = 26;
        } else {
            A[i] += mod;
            mod = 0;
        }
    }
    for(int i: A)
        cout << (char)('a' + i - 1);
    cout << endl;
    return 0;
}
