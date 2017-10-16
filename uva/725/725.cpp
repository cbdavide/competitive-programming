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

bool check(int abcde, int fghij){
    int used = (fghij < 10000);
    while(abcde) {used |= 1 << (abcde % 10); abcde /= 10;}
    while(fghij) {used |= 1 << (fghij % 10); fghij /= 10;}
    return used == ((1 << 10) - 1);
}

int main() {
    int n, k, t=0;
    while(cin >> n && n) {
        if(t++) cout << endl;
        k = 1;
        rep(fghij, 1234, (98765 / n) + 1) {
            int abcde = n * fghij;
            if(check(abcde, fghij) && k++)
                printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
        }
        if(k == 1)
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}