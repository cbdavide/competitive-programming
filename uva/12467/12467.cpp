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

void failure(string w, vi &table) {
    int i, j;
    j = 0; i = size(w) - 1;
    table[0] = 0;
    while(i >= 0) {
        if(w[j] == w[i]) {
            table[i] = j + 1;
            j++; i--;
        } else if(j > 0) {
            j = table[j + 1];
        } else {
            table[i] = 0;
            i--;
        }
    }
}

int main() {
    int idx;
    string word, temp;
    int t; cin >> t;
    while(t--) {
        cin >> word;
        
        vi T(size(word));
        failure(word, T);

        idx = 0;
        rep(i, 1, size(T)) {
            if(T[i] > T[idx])
                idx = i;
        }

        cout << word.substr(idx, T[idx]) << endl;
    }
    return 0;
}