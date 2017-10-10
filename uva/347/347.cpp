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
typedef vector<bool> vb;

const int INF = ~(1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

void increment(vi &A, int i) {
    while(true) {
        if(i < 0) {
            A.insert(A.begin(), 0);
            i = 0;
        }
        A[i] = mod(A[i] + 1, 10);
        if(!A[i]) A[i] = 1;
        else break;
        i--;
    }
    rep(j, i + 1, size(A)) A[j] = 1;
}

void next(vi &A) {
    bool cond;
    while(true) {
        vi T(10); cond = true;
        rep(i, 0, size(A)) {
            if(T[A[i]] + 1 == 2 || !A[i]) {
                increment(A, i);
                cond = false; break;
            } else T[A[i]]++;
        }
        if(cond)break;       
    }
}

bool check(vb &A) {
    iter(itr, A)
        if(!(*itr)) return false;
    return true;
}


int main() {
    int n, idx, t = 1;
    string num;

    while(cin >> n && n != 0) {
        idx = -1; num = to_string(n);
        vi A(size(num)); vb vis(size(num));
        rep(i, 0, size(num)) A[i] = num[i] - '0';

        while(true) {
            idx = 0; next(A);
            vis.assign(size(A), 0);
            rep(z, 0, size(A)) {
                vis[idx] = true;
                idx = mod(idx + A[idx], size(A));
            }

            if(check(vis) && idx == 0) break;

            increment(A, size(A) - 1);
            
        }
        cout << "Case " << t++ << ": ";
        iter(itr, A) cout << *itr;
        cout << endl;
    }
    return 0;
} 
// 12577
// 12554
// 12478