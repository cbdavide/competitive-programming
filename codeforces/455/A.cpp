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

typedef vector<ll> vll;

int main() {
    int MAX = 100001;
    ll n, t; cin >> n;
    vll nums(MAX), dp(MAX);
    rep(i, 0, n) {
        cin >> t;
        nums[t]++;
    }

    dp[1] = nums[1];
    rep(i, 2, MAX)
        dp[i] = max(dp[i - 1], dp[i - 2] + (i * nums[i]));
    cout << dp[MAX - 1] << endl;
    return 0;
}