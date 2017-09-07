#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

string s;
const int N_MAX = 1000;
int n, m, sa[N_MAX], rk[N_MAX], lcp[N_MAX];
ll rk2[N_MAX];

bool cmp(int i, int j) {
    return rk2[i] < rk2[j];
}

void suffix_array() {
    for(int i=0; i<n; i++) {
        sa[i] = i; rk[i] = s[i]; rk2[i] = 0;
    }

    for(int l=1; l<n; l<<=1) {
        for(int i=0; i<n; i++) {
            rk2[i] = ((ll) rk[i] << 32) + (i + l < n ? rk[i + l] : -1);
        }
        sort(sa, sa + n, cmp);
        for(int i=0; i<n; i++) {
            if(i > 0 && rk2[sa[i]] == rk2[sa[i - 1]])
                rk[sa[i]] = rk[sa[i - 1]];
            else rk[sa[i]] = i;
        }
    }
}

void build_lcp() {
    for(int i=0; i<n; i++) rk[sa[i]] = i;
    for(int i=0, l=0; i<n; i++) {
        if(rk[i] > 0) {
            int j = sa[rk[i] - 1];
            while(s[i + l] == s[j + l]) l++;
            lcp[rk[i]] = l;
            if(l > 0) l--;
        }
    }
}

set<string> lcs() {
    set<string> si;
    int ind = 0, lcs_i = -1;
    for(int i=1; i<n; i++) {
        if(((sa[i] < n - m - 1) != (sa[i - 1] < n - m - 1)) && lcp[i] > lcs_i)
            lcs_i = lcp[i];
    }
    if(lcs_i == 0) return si;
    for(int i=1; i<n; i++) {
        if(((sa[i] < n - m - 1) != (sa[i - 1] < n - m - 1)) && lcp[i] == lcs_i) {
            si.insert(s.substr(sa[i], lcp[i]));
        }

    }
    return si;
}

int main() {
    string a, b, c;
    bool cond = false;
    while(cin >> a >> b) {
        if(cond) cout << '\n';
        s = a + "#" + b + "$";

        n = s.size(); m = b.size();
        suffix_array(); build_lcp();

        set<string> idx = lcs();

        if(idx.empty()) {
            cout << "No common sequence.\n";
        } else {
            set<string>::iterator i = idx.begin();
            for( ; i!=idx.end(); i++)
                cout << *i << '\n';
        }
        cond = true;
    }
    return 0;
}
