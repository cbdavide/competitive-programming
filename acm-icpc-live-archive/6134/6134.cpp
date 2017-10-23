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

bool check(int n) {
    int used = 0, digit;
    while(n) {
        digit = n % 10;
        if(used & (1 << digit)) return false;
        used |= (1 << digit);
        n /= 10;
    }
    return true;
}

int main() {
    int n, m, cont;
    while(cin >> n >> m){
        cont = 0;
        rep(i, n, m + 1)
            if(check(i)) cont++;
        cout << cont << endl;
    }
    return 0;
}