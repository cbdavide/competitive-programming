#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

struct entry {ii nr; int p;};
bool operator <(const entry &a, const entry &b) {
    if(a.nr == b.nr) return a.p <= b.p;
    return a.nr < b.nr;
}

struct suffix_array {
    string s; int n; vvi P; vi idx;
    vector<entry> L;

    suffix_array(string _s) : s(_s), n(s.size()) {
        L = vector<entry>(n);
        P.push_back(vi(n));
        idx = vi(n);
        for(int i=0; i<n; i++) P[0][i] = s[i];
        for(int stp = 1, cnt = 1; cnt < n; stp++, cnt <<= 1) {
            P.push_back(vi(n));
            for(int i=0; i<n; i++) {
                L[i].p = i;
                L[i].nr = ii(P[stp - 1][i], P[stp-1][(i+cnt) % n]);
            }
            sort(L.begin(), L.end());

            int cont = 0;
            for(int i=0; i<n; i++) {
                P[stp][L[i].p] = i > 0 &&
                L[i].nr == L[i-1].nr ? P[stp][L[i - 1].p] : cont++;
            }
        }
        for(int i=n-1; i>=0; i--) idx[P[P.size() - 1][i]] = i;
    }
};

int main() {
    int n, i; string s;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        string temp = s + s;
        suffix_array sf(s);

        cout << sf.idx[0] + 1 << endl;
    }
    return 0;
}
