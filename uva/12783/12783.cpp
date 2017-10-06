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

vi num, low, parent;
vii answ;
int cont;

void bridges(vvi &G, int s) {
    low[s] = num[s] = cont++;
    
    iter(v, G[s]) {

        if(num[*v] == -1) {
            parent[*v] = s;
            bridges(G, *v);

            if(low[*v] > num[s])
                answ.push_back(ii(min(s, *v), max(s, *v)));
            low[s] = min(low[s], low[*v]);

        } else if(*v != parent[s]){
            low[s] = min(low[s], num[*v]);
        }
    }
}

int main() {
    int V, E, u, v;
    while(cin >> V >> E && (E + V)) {
        vvi G(V);
        num.assign(V, -1); low.assign(V, 0);
        parent.assign(V, 0); cont = 0;
        answ.clear();
        rep(i, 0, E) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        rep(i, 0, V) {
            if(num[i] == -1)
                bridges(G, i);
        }
        sort(answ.begin(), answ.end());
        cout << size(answ);
        rep(i, 0, size(answ)) {
            cout << ' ' << answ[i].F << ' ' << answ[i].S;
        }
        cout << endl;
    }
    return 0;
}