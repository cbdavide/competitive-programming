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

typedef vector<bool> vb;

bool all_true(vb F) {
    iter(it, F) 
        if(!(*it)) return false;
    return true;
}

bool check(vb &F) {
    int cont = 0;
    rep(i, 0, size(F))
        if(!F[i]) cont++;

    if(!cont) return false;
    return cont == 1;
}

int main() {
    char c;
    int t, n, k, z, cond = 0;
    cin >> t;
    while(t--) {
        if(cond++ > 0) cout << endl;
        cin >> n >> k;

        vb F(n), F2(n);

        rep(i, 0, k) {

            cin >> z;
            vi left(z), right(z);

            rep(i, 0, z) cin >> left[i];
            rep(i, 0, z) cin >> right[i];

            cin >> c;

            if(c == '<') {

                rep(i, 0, z) {
                    F[left[i] - 1] = true;
                    F2[right[i] - 1] = true;
                }
                

            } else if(c == '>') {

                rep(i, 0, z) {
                    F[right[i] - 1] = true;
                    F2[left[i] - 1] = true;
                }

            } else {

                rep(i, 0, z) {
                    F[left[i] - 1] = true;
                    F[right[i] - 1] = true;

                    F2[left[i] - 1] = true;
                    F2[right[i] - 1] = true;
                }

            }
        }

        if(all_true(F) && check(F2)) {
            rep(i, 0, size(F2)) {
                if(!F2[i]) {
                    cout << i + 1 << endl;
                    break;
                }
            }
        } else if(all_true(F2) && check(F)) {
            rep(i, 0, size(F)) {
                if(!F[i]) {
                    cout << i + 1 << endl;
                    break;
                }
            }
        } else if(check(F) && check(F2)) {
            bool a = false;
            rep(i, 0, size(F)) {
                if(!F[i] && !F2[i]) {
                    cout << i + 1 << endl;
                    a = true;
                    break;
                }

            }
            if(!a) cout << "0" << endl;

        } else {
            cout << "0" << endl;
        }

    }
    return 0;
}