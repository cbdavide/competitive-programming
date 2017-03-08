#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int bnsearch(int *arr, int n, int w) {
    int lo = *max_element(arr, arr + n);
    int hi = accumulate(arr, arr + n, 0);

    while(lo < hi) {
        int x = lo + (hi - lo) / 2;
        int required = 1, current_load = 0;
        for(int i=0; i<n; i++) {
            if(current_load + arr[i] <= x) {
                current_load += arr[i];
            }else {
                required++;
                current_load = arr[i];
            }
        }
        if(required <= w)
            hi = x;
        else
            lo = x + 1;
    }

    return lo;
}
int main() {
    int t, n, w, p, *enes, maxi, pay;
    cin >> t;
    while(t--) {
        cin >> n >> w >> p;
        enes = new int[n];
        for(int i=0; i<n; i++) cin >> enes[i];
        maxi = bnsearch(enes, n, w);
        printf("%d $%d\n", maxi, (maxi * p * w));
    }
    return 0;
}
