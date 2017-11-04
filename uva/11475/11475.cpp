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

bool failure(string &w, int idx) {
    int i, j;
    j = idx; i = size(w)-1;
    while(i>=idx) {
        if(w[j] == w[i])i--, j++;
        else break;
    }
    return i < idx;
}

int main() {
    bool cond;
    string word;
    while(cin >> word) {
        cond = true;
        rep(i, 0, size(word) - 1) {
            if(failure(word, i)) {
                string f = word.substr(0, i);
                reverse(f.begin(), f.end());
                cout << word + f << endl;
                cond = false;
                break;
            }
        }
        if(cond) {
            string f = word.substr(0, size(word) - 1);
            reverse(f.begin(), f.end());
            cout << word + f << endl;
        }
    }
    return 0;
}