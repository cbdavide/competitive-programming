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
const double EPS = 1e-12;
const double PI = acos(-1);

int main() {
    int v, v0, answ, n;
    double val = 0.0, r; 
    while(cin >> v >> v0 && (v + v0)) {
        n = 1; answ = 0; val = 0.0;
        while((((double)v / n) - v0) > 0) {

            r = (0.3d * sqrt(((double)v / n) - v0)) * n;
            if(r >= val) {
                if(fabs(r - val) < EPS) {
                    answ = 0;
                    break;
                }
                val = r;
                answ = n;
            }
            n++;
        }
        cout << answ << endl;
    }
    return 0;
}