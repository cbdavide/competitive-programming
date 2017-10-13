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

int z_algorithm(string &P, string &T) {
    string s = P + " " + T;
    int l = 0, r = 0, n = size(s);
    vi z(n); int cont = 0;
    rep(i, 1, n) {
        z[i] = 0;
        if(i > r) {
            l = r = i;
            while(r < n && s[r - l] == s[r]) r++;
            z[i] = r - l; r--;
        } else if(z[i - l] < r - i + 1) z[i] = z[i - l];
        else {
            l = i;
            while(r < n && s[r - l] == s[r]) r++;
            z[i] = r - l; r--;
        }
        if(z[i] == size(P)) cont++;
    }
    return cont;
}

int check(string &line, int i) {
    int cont;
    string P = line.substr(0, i);
    string T = line.substr(i);
    cont = z_algorithm(P, T) + 1;
    return cont;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool cond;
    int r, s;
    string line;

    while(cin >> line && line != ".") {
        s = size(line); cond = true;
        rep(i, 1, ceil(s / 2) + 1) {

            if(s % i == 0) {
                r = check(line, i);
                if(r == (s / i)) {
                    cout  << s / i << endl;
                    cond = false;
                    break;
                }
            } 
        }
        if(cond) cout << 1 << endl;
    }
    return 0;
}