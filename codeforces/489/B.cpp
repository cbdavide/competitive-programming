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
    int b, g;

    cin >> b;
    vi B(b);
    rep(i, 0, b) cin >> B[i];

    cin >> g;
    vi G(g);
    rep(i, 0, g) cin >> G[i];

    sort(B.begin(), B.end());
    sort(G.begin(), G.end());

    int dp[b + 1][g + 1];
    rep(i, 0, b + 1) {
        rep(j, 0, g + 1) {
            if(!i || !j) dp[i][j] = 0;
            else {
                if(abs(B[i - 1] - abs(G[j - 1])) <= 1) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[b][g] << endl;
    return 0;
}