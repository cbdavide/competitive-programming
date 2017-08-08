#include <bits/stdc++.h>
using namespace std;

bool check(int *arr, int n, int k, int mid) {
    int cont = k;
    for(int i=n-1; i>=0; i--) {
        cont -= arr[i] / mid;
        if(cont <= 0) return true;
    }
    return false;
}

int main() {
    int n, k, t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int *nums = new int[n];
        for(int i=0; i<n; i++) cin >> nums[i];
        sort(nums, nums + n);

        int lo = 1, hi = nums[n - 1] + 1, mid;

        while(lo < hi) {
            mid = lo + (hi - lo) / 2;

            if(check(nums, n, k, mid)) lo = mid + 1;
            else hi = mid;
        }
        cout << lo - 1 << '\n';
    }
    return 0;
}
