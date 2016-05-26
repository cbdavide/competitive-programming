#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r, s, t;
    bool *nn;
    vector<int> rr;

    cin >> n >> s >> r;

    nn = new bool[n];

    memset(nn, 1, n);

    for(int i=0; i<s; i++){
        cin >> t;
        nn[t-1] = false;
    }


    for(int i=0; i<r; i++) {
        cin >> t;
        if(!nn[t-1])
            nn[t-1] = 1;
        else
            rr.push_back(t-1);
    }

    sort(rr.begin(), rr.end());

    for(int i=0; i<rr.size(); i++){
        if(rr[i] > 0 && !nn[rr[i]-1])
            nn[rr[i]-1] = 1;
        else if(rr[i] < n-1 && !nn[rr[i]+1])
            nn[rr[i]+1] = 1;
    }

    t = 0;
    for(int i=0; i<n; i++){
        if(!nn[i])
            t++;
    }

    cout << t << '\n';

    return 0;
}
