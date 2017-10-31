#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T &x) {return x.size();}
template <class T> T mod(T a, T b) { return (b + (a % b)) % b;}

#define F first
#define S second
#define PB push_back
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

typedef vector<ll> vll;

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main() {
    int n;
    double num;
    while(cin >> num && num) {
        n = round(num * 100);

        vll dp(n + 1); dp[0] = 1LL;
        rep(i, 0, 11) {
            rep(j, coins[i], size(dp))
                dp[j] += dp[j - coins[i]];
        }
        // cout << dp[n] << endl;
        printf("%6.2f%17lld\n", num, dp[n]);
    }
    return 0;
}