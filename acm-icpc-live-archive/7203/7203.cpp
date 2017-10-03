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

typedef map<char, int> msa;

int check(string num) {
    msa dic;
    rep(i, 0, size(num)) {
        dic[num[i]]++;
        if(dic[num[i]] == 3) {
            while(num[i] == '0') i--;
            return i;
        }
    }
    return INF;
}

void detract(string &num, int idx) {
    int nex = (num[idx] - '0') - 1;
    num[idx] = nex + '0';
    rep(i, idx + 1, size(num))
        num[i] = '9';
}

int main() {
    int idx;
    string num;
    while(cin >> num) {
        
        while((idx = check(num)) != INF)
            detract(num, idx);

        while(num.front() == '0')
            num.erase(num.begin());
        cout << num << endl;

    }
    return 0;
}