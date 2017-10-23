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
    int n, k, diff, cont = 0;
    cin >> n >> k;
    vi A(n);
    rep(i, 0, n) cin >> A[i];
    rep(i, 1, n) {
        if(A[i - 1] + A[i] < k) {
            diff = k - (A[i - 1] + A[i]);
            cont += diff;
            A[i] += diff;
        }
    }
    cout << cont << endl;
    iter(it, A) cout << (*it) << ' ';
    cout << endl;
    return 0;
}