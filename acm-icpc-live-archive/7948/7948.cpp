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
typedef vector<string> vs;

const int INF = (1 << 30);
const double EPS = 1e-9;
const double PI = acos(-1);

bool cmp(string a, string b) {
    char last = a.back();
    a.insert(a.begin(), last);
    a.pop_back(); 
    return a == b;
}

vs chop(string word, int s) {
    int i=0; vs chops;
    while(i < size(word)) {
        chops.push_back(word.substr(i, s));
        i += s;
    }
    return chops;
}


bool check(string word, int s) {
    vs chops = chop(word, s);
    rep(i, 0, size(chops) - 1) {
        if(!cmp(chops[i], chops[i + 1]))
            return false;
    }
    return true;
}

int main() {
    string line;
    while(cin >> line) {
        bool cond = false;
        rep(i, 1, size(line)) {
            if(!(size(line) % i) && check(line, i)) {
                cout << i << endl;
                cond = true; i = INF;
            }
        }
        if(!cond) cout << size(line) << endl;
    }
    return 0;
}

