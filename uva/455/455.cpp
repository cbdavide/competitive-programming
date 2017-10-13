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

int check(string line, int i) {
    int cont = 1, j=0;
    string P = line.substr(0, i);
    string T = line.substr(i);

    while((j = T.find(P, j)) != string::npos) {
        j += size(P);
        cont++;
    }
    return cont;
}

int main() {
    bool cond;
    string line;
    int n, s, cont = 0; cin >> n;
    while(n--){
        if(cont++ > 0) cout << endl;

        cond = false;
        cin >> line;
        s = size(line);
        rep(i, 1, s) {
            if(s % i == 0) {
                if(check(line, i) == s / i) {
                    cout <<  i  << endl;
                    cond = true;
                    break;
                }
            }
        }
        if(!cond) cout << size(line) << endl;
    }
    return 0;
}