#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void lci(vi &A) {
    vi DP (A.size(), 1);
    vi path(A.size());
    for(int i=0; i<(int)A.size(); i++)
        path[i] = i;

    for(int i=1; i<(int)A.size(); i++) {
        for(int j=0; j<i; j++) {
            if(A[j] < A[i]) {
                if(DP[i] < DP[j] + 1) {
                    DP[i] = DP[j] + 1;
                    path[i] = j;
                }
            }
        }
    }

    int max_i = 0;
    for(int i=0; i<(int)DP.size(); i++)
        if(DP[i] > DP[max_i]) max_i = i;

    cout << "Max hits: " << DP[max_i] << '\n';
    vi order;
    while(path[max_i] != max_i) {
        order.push_back(A[max_i]);
        max_i = path[max_i];
    }
    order.push_back(A[max_i]);
    for(int i=(int)order.size()-1; i>=0; i--)
        cout << order[i] << '\n';
}

int main() {
    int t; vi arr;
    string n;
    cin >> t; getline(cin, n); getline(cin, n);
    while(t--) {
        while(getline(cin, n) && n != "") arr.push_back(stoi(n));
        lci(arr); arr.clear();
        if(t > 0) cout << '\n';
    }
    return 0;
}
