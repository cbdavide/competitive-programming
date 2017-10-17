#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T &x) {return x.size();}
template <class T> T mod(T a, T b) { return (b + (a % b)) % b;}

#define F first
#define S second
#define endl '\n'
#define rep(i, a, b) for(__typeof(a) i=a; i<(b); i++)
#define iter(it, c) for(__typeof((c).begin()) it=(c).begin(); \
 it != (c).end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef set<int> si;

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

int main() {
    char c;
    string line;
    int t, k, m, z, total;

    cin >> t;
    while(t--) {
        map<char, int> value;
        cin >> k;

        rep(i, 0, k) {
            cin >> c >> z;
            value[c] = z;
        }

        cin >> m; total = 0;
        getline(cin, line);
        while(m--) {
            getline(cin, line);

            iter(it, line) 
                total += value[*it];


        }

        printf("%d.%.2d$\n", total / 100, total % 100);
    }
    return 0;
}