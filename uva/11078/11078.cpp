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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, t; cin >> t;
    while(t--) {
        cin >> n;
        vi A(n);
        rep(i, 0, n) cin >> A[i];
        int maxi = -INF, mini = -INF;

        rep(i, 0, n - 1) {
            maxi = max(maxi, A[i]);
            mini = max(mini, maxi - A[i + 1]);
        }

        cout << mini << endl;
    }
    return 0;
}