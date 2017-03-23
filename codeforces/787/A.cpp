#include <bits/stdc++.h>
using namespace std;

#define MAX 2147483647
#define MIN -2147483647
#define ll long long
#define endl '\n'

typedef pair<int, int> pii;
typedef set<int> si;
typedef vector<int> vi;
typedef map<string, int> msi;

int main() {
    int a, b, c, d, an, bn;
    si vals;
    pii r;

    cin >> a >> b;
    cin >> c >> d;


    for(int i=1; i<10000; i++) {
        an = b + (a * (i - 1));
        bn = d + (c * (i - 1));

        if(!vals.insert(an).second) {// an is the answer
            cout << an << endl;
            return 0;
        }

    if(!vals.insert(bn).second) {// bn is the answer
            cout << bn << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
