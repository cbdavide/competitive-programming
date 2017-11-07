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

typedef vector<char> vc;
typedef set<char> sc;
typedef map<char, sc> csc;
typedef map<char, int> ci;
typedef map<char, bool> cb;

csc G;
ci indegree;
cb vis; vc res;

void all_topsort() {

    bool flag = false;
    iter(it, G) {
        char v = (*it).F;
        sc list = (*it).S;

        if(!indegree[v] && !vis[v]) {
            iter(ot, list)
                indegree[*ot]--;

            res.PB(v);
            vis[v] = true;

            all_topsort();

            res.pop_back();
            vis[v] = false;

            iter(ot, list)
                indegree[*ot]++;

            flag = true;
        }

    }

    if(!flag) {
        iter(it, res) cout << *it;
        cout << endl;
    }

}


int main() {
    int cont = 0;
    char x, y;
    string l1, l2;
    while(getline(cin, l1)) {
        if(cont++ > 0) cout << endl;
        
        G.clear(); indegree.clear();
        res.clear(); vis.clear();
        getline(cin, l2);

        stringstream tt(l1);
        while(tt >> x) G[x];

        stringstream ss(l2);
        while(ss >> x >> y){
            G[x].insert(y);
            indegree[y]++;
        }

        all_topsort();
    }
    return 0;
}