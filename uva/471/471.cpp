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

typedef vector<bool> vb;

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

int check(ll n) {
    string num = to_string(n);
    if(size(num) > 10) return 1;
    vi vis(10);
    rep(i, 0, size(num)) 
        if(++vis[num[i] - '0'] == 2) return 2;
    
    return 3;
}

int main() {
    int t, z = 1; ll n, s1;
    cin >> t;
    while(t--) {
        if(z++ > 1) cout << endl;
        cin >> n;
        for(ll i=1LL; ; i++) {
            if(check(i) == 2) continue;
            s1 = n * i;
            int r = check(s1);
            if(r == 1)  break;
            else if(r == 3) 
                cout << s1 << " / " << i << " = " << n << endl;
        }
    }
    return 0;
}