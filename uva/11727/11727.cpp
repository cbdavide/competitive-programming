#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, l, r, s;
    cin >> t;
    for(int z=1; z<=t; z++) {
        int nums[3];
        cin >> nums[0] >> nums[1] >> nums[2];
        sort(nums, nums + 3);
        cout << "Case " << z << ": " << nums[1] << "\n";
    }
    return 0;
}
