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

const int MAX = 1010;
bitset<MAX> bs;
vi primes;

void build_sieve() {
    bs.set();
    primes.PB(1);
    rep(i, 2LL, MAX + 1) {
        if(bs[i]) {
            for(ll j=i*i; j<=MAX; j+=i)
                bs[j] = false;
            primes.PB((int)i);
        }
    }
}

int find(int num) {
    vi::iterator vit;
    vit = lower_bound(primes.begin(), primes.end(), num);
    if(*vit > num) vit--;
    return (vit - primes.begin()) + 1;
}

int main() {
    int n, c;
    build_sieve();
    while(cin >> n >> c) {
       int r = find(n), mid = r / 2;

       int end, begin;

       end = (r % 2 == 0) ? 2 * c : 2 * c - 1;
       begin = (r % 2 == 0) ? mid - c : mid - c + 1;

       begin = begin < 0 ? 0 : begin;
       end = end > r ? r : end;

       printf("%d %d:", n, c);
       rep(i, 0, end) {
            cout << ' ' << primes[begin + i];
       }cout << endl << endl;
    }
    return 0;
}