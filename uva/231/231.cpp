    #include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int lds(vi &A) {
    vi DP((int)A.size(), 1);

    for(int i=1; i<(int)A.size(); i++) {
        for(int j=0; j<i; j++) {
            if(A[j] >= A[i])
                DP[i] = max(DP[i], DP[j] + 1);
        }
    }

    int maxi = 0;
    for(int i=0; i<DP.size(); i++)
        maxi = max(maxi, DP[i]);
    return maxi;
}

int main() {
    int n, t = 0; vi arr;
    while(cin >> n) {
        if(n == -1) {
            if((int)arr.size() == 0) break;
            else if(t > 0)cout << '\n';
            int answ = lsi(arr);
            cout << "Test #" << ++t << ":\n";
            cout << "  maximum possible interceptions: " << lds(arr) << '\n';
            arr.clear();
        } else {
            arr.push_back(n);
        }
    }
    return 0;
}
