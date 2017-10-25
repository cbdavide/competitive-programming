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

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

const int MAX = 1000010;
bitset<MAX> bs;

void buld_sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    rep(i, 2LL, MAX + 1) {
        if(bs[i]) {
            for(ll j=i*i; j<=MAX; j+=i)
                bs[j] = false;
        }
    }
}

int main() {
    int n, other;
    buld_sieve();
    while(cin >> n && n) {
        for(int i=3; i<=n/2; i += 2) {
            other = n - i; 
            if(bs[i] && bs[other]) {
                printf("%d = %d + %d\n", n, i, other);
                break;
            }
        }
    }
    return 0;
}