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

typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef pair<double, ii> dii;
typedef vector<dii> vdii;

double dist(dd &a, dd &b) {
    return sqrt(pow(a.F - b.F, 2) + pow(a.S - b.S, 2));
}

struct union_find {
    vi data, pe;
    union_find(int n) : data(vi(n)), pe(vi(n)) {
        rep(i, 0, size(data)) data[i] = i;
    }
    int find(int x) {
        if(data[x] == x) return x;
        data[x] = find(data[x]);
        return data[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        if(pe[px] > pe[py]) swap(px, py);
        pe[px] += pe[py];
        data[py] = px;
        return true;
    }
};

double mst(vdii &E, int V) {
    double weight = 0;
    union_find uf(V);
    sort(E.begin(), E.end());
    iter(it, E) {
        int x = (*it).S.F, y = (*it).S.S;
        if(uf.unite(x, y)) {
            weight += (*it).F;
        }
    }
    return weight;
}

int main() {
    int t, V;
    double x, y;
    cin >> t;
    rep(z, 0, t) {
        if(z > 0) cout << endl;

        cin >> V;
        vdd point(V);
        rep(i, 0, V) {
            cin >> x >> y;
            point[i] = ii(x, y);
        }
        vdii list;
        rep(i, 0, V) {
            rep(j, i + 1, V) {
                list.PB(dii(dist(point[i], point[j]), ii(i, j)));
            }
        }
        printf("%.2f\n", mst(list, V));
    }
    return 0;
}