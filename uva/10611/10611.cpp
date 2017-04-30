#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator viterator;

int main() {
    int t, a;
    viterator shorter, greater;

    cin >> t;
    vi arr(t);

    for(int i=0; i<t; i++) cin >> arr[i];
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> a;

        shorter = lower_bound(arr.begin(), arr.end(), a);
        greater = upper_bound(arr.begin(), arr.end(), a);

        if(shorter == arr.begin()) cout << "X ";
        else cout << *(--shorter) << ' ';

        if(greater == arr.end()) cout << "X\n";
        else cout << *greater << '\n';
    }
    return 0;
}
