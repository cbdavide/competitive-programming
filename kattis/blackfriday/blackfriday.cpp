#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, i;
    int arr[7] = {0, 0, 0, 0, 0, 0, 0};
    map<int, int> idx;

    cin >> n;
    for(i=0; i<n; i++) {
        cin >> l;
        arr[l]++;
        idx[l] = i;
    }

    for(i=6; i>=1; i--)
        if(arr[i] == 1) break;

    if(i > 0)cout << idx[i] + 1<< '\n';
    else cout << "none\n";
    return 0;
}
