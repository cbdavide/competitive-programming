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
    map<int, char> dic;
    dic[0] = 'N'; dic[1] = 'E'; dic[2] = 'S'; dic[3] = 'W';

    string line;
    int n, m, x, y, z = 0;
    int t, pos; 
    bool cond;

    cin >> t;
    while(t--) {
        if(z++ > 0) cout << endl;

        cin >> n >> m;
        char mat[n][m];

        getline(cin, line);
        rep(i, 0, n) {
            getline(cin, line);
            rep(j, 0, m) 
                mat[i][j] = line[j];
        }

        cin >> x >> y;
        x--; y--;
        getline(cin, line);
        pos = 0; cond = true;

        while(cond) {
            getline(cin, line);
            iter(it, line) {
                if(*it == 'R') {

                    pos = mod(pos + 1, 4);

                } else if(*it == 'L') {

                    pos = mod(pos - 1, 4);                    

                } else if(*it == 'F') {

                    int tx = x, ty = y;

                    if(pos == 0) tx--;
                    else if(pos == 1) ty++;
                    else if(pos == 2) tx++;
                    else ty--;

                    if(tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        if(mat[tx][ty] != '*') {
                            x = tx; y = ty;
                        }
                    }

                } else if(*it == 'Q'){
                    cond = false;
                    break;
                }
            }
        }
        printf("%d %d %c\n", x+1, y+1, dic[pos]);
    }
    return 0;
}