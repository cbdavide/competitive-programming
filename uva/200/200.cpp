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

typedef vector<string> vs;
typedef vector<char> vc;
typedef map<char, vc> mcvs;
typedef map<char, bool> mcb;

mcvs G;
mcb vis; vc res;

void topsort(char s) {
    vis[s] = true;
    iter(it, G[s]) {
        if(!vis[*it])
            topsort(*it);
    }
    res.PB(s);
}


int main() {
    string w;
    vs words;
    while(cin >> w) {
        if(w == "#") {
            rep(i, 0, size(words)) {
                rep(j, i + 1, size(words)) {
                    for(int k=0; k<size(words[i]) && k<size(words[j]); k++) {
                        if(words[i][k] != words[j][k]) {
                            G[words[i][k]].PB(words[j][k]);
                            break;
                        }
                    }
                }
            }
            topsort(words[0][0]);
            for(int i=size(res)-1; i>=0; i--)
                cout << res[i];
            cout << endl;
            
            G.clear(); vis.clear();
            res.clear();
        } else {
            words.PB(w);
        }
    }
    return 0;
}