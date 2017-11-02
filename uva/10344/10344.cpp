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

int t[5], state[4];

bool check() {
    rep(i, 0, 5){
        if(t[i]) return true;
    }
    return false;
}

bool back(int c, int h) {
    if(c == 5) {
        if(h == 23) return true;
        return false;
    }

    return back(c + 1, h + t[c]) || back(c + 1, h - t[c]) || back(c + 1, h * t[c]);
}

int main() {
    bool cond = false;
    while(cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4]) {
        if(!check()) break;

        sort(t, t + 5);

        do {
            if(cond = back(1, t[0]))break;
        }while(next_permutation(t, t + 5));

        if(!cond) cout << "Impossible\n";
        else cout << "Possible\n";

    }
    return 0;
}