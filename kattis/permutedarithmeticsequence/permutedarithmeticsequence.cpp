#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool is_sq(vi &arr) {
    int diff = arr[1] - arr[0];
    for(int i=2; i<arr.size(); i++) {
        if(arr[i] - arr[i - 1] != diff)
            return false;
    }
    return true;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vi sq(n);
        for(int i=0; i<n; i++) cin >> sq[i];
        if(is_sq(sq)) cout << "arithmetic\n";
        else {
            sort(sq.begin(), sq.end());
            if(is_sq(sq)) cout << "permuted arithmetic\n";
            else cout << "non-arithmetic\n";
        }
    }
    return 0;
}
