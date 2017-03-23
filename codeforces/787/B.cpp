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

bool test(const vi &a, const vi &b) {
    for(int i=1; i<a.size(); i++) {
        if(a[i] == 2 && b[i] == 2)
            return false;
    }
    return true;
}

int main() {
    int n, m, k, a;

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> k;
        vi ricks(n + 1, 0);
        vi mortys(n + 1, 0);
        for(int i=0; i<k; i++) {
            cin >> a;
            if(a < 0) mortys[abs(a)] = 2;
            else ricks[a] = 2;
        }

        if(test(ricks, mortys)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
