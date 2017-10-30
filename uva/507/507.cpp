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

int main() {
    int t, n, mi, ai, me, ne;
    int max_cur, max_far;
    cin >> t;
    for(int z=1; z<=t; z++) {
        cin >> n;

        vi A(--n);
        rep(i, 0, n) cin >> A[i];

        max_cur = 0; max_far = 0;
        ai = mi = 0; me = ne = 0;

        rep(i, 0, n) {
            ne++;
            max_cur += A[i];

            if(max_cur < 0) {
                max_cur = 0;
                ai = i + 1; ne = 0;
            }

            if(max_cur > max_far) {

                max_far = max_cur;
                me = ne;
                mi = ai;

            } else if(max_cur == max_far){

                if(ne > me)
                    mi = ai, me = ne;
                else if(ne == me) {
                    if(ai < mi) mi = ai;
                }
            }
        }
        if(me == 0) mi = ai, me = ne;
        if(!max_far) printf("Route %d has no nice parts\n", z);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", z, mi + 1, mi + me + 1);
    }
    return 0;
}