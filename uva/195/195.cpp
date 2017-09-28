#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T &x) {return x.size();}
template <class T> T mod(T a, T b) { return (b + (a % b)) % b;}

#define F first
#define S second
#define endl '\n'
#define rep(i, a, b) for(typeof(a) i=a; i<(b); i++)
#define iter(it, c) for(typeof((c).begin()) it=(c).begin(); \
 it != (c).end(); it++)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef set<int> si;

const int INF = (1 << 31);
const double EPS = 1e-9;
const double PI = acos(-1);

bool cmp(char a, char b) {
	if(tolower(a) != tolower(b)) 
		return tolower(a) < tolower(b);
	return a < b;
}

int main() {
	string line;
	int t; cin >> t;
	while(t--) {
		cin >> line;
		sort(line.begin(), line.end(), cmp);
		do {
			cout << line << endl;
		}while(next_permutation(line.begin(), line.end(), cmp));
	}
	return 0;
}