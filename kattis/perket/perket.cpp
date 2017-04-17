#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int find_min(vpii &arr) {
    int mini = MAX;
    int size = pow(2, arr.size());
    for(int i=1; i<size; i++) {
        int s = 1, b = 0;
        for(int j=0; j<arr.size(); j++) {
            if(i & (1 << j)) {//Element j is in the bag
                s *= arr[j].first;
                b += arr[j].second;
            }
        }
        mini = min(mini, abs(s - b));
    }
    return mini;
}

int main() {
    int n, a, b;
    cin >> n;
    vpii ingredients(n);
    for(int i=0; i<n; i++){
        cin >> a >> b;
        ingredients[i] = pii(a, b);
    }
    cout << find_min(ingredients) << '\n';
    return 0;
}
