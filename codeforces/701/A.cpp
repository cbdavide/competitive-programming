#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
    int n, a, b;
    cin >> n;
    vpii arr(n);
    for(int i=0; i<n; i++) {
        cin >> a ;
        arr[i] = pii(a, i + 1);
    }
    sort(arr.begin(), arr.end());
    for(int i=0, j=arr.size() - 1; i < j; i++, j--)
        cout << arr[i].second << ' ' << arr[j].second << endl;

    return 0;
}
