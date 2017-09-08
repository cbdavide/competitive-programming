#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
const int N_MAX = 5010;
int sa[N_MAX], rk[N_MAX], lcp[N_MAX];
ll rk2[N_MAX];

bool cmp(int i, int j) {
    return rk2[i] < rk2[j];
}

void suffix_array() {
    for(int i=0; i<n; i++) {
        sa[i] = i; rk[i] = s[i]; rk2[i] = 0;
    }

    for(int l=1; l<n; l<<=1) {
        for(int i=0; i<n; i++)
            rk2[i] = ((ll)rk[i] << 32) + (i + l < n ? rk[i + l] : -1);
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

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> s;
        n = s.size();
        suffix_array();
        build_lcp();
        cout << *max_element(lcp, lcp + n) << '\n';
    }
    return 0;
}
