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
    int q, a, b;
    string line;
    cin >> line;
    vi A(size(line));
    rep(i, 0, size(A) - 1) {
        A[i + 1] = A[i];
        if(line[i] == line[i + 1])
            A[i + 1]++;
    }
    cin >> q;
    rep(i, 0, q) {
        cin >> a >> b;
        cout << A[--b] - A[--a] << endl;
    }
    // iter(it, A) cout << (*it) << ' '; cout << endl;
    return 0;
}