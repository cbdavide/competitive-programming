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
    int n, m, b, t;
    int arr[5] = {1, 10, 100, 1000, 10000};
    while(cin >> n >> m) {
        int result, daedalus, budg;
        int o_points = 0, d_points = 0;
        rep(i, 0, m) {
            cin >> budg >> daedalus;
            result = daedalus;
            rep(i, 1, n) {
                cin >> t;
                result += t;
            }

            if(result <= budg)
                o_points += daedalus;
            
            result -= daedalus;
            for(int i=4; i>=0; i--) {
                if(result + arr[i] <= budg){
                    d_points += arr[i];
                    break;
                }
            }
        }
        cout << (d_points - o_points) << endl;
    }
    return 0;
}   