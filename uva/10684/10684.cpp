#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    int n, max_so_far, curr_max;
    while(cin >> n && n) {
        vi nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        max_so_far = nums[0], curr_max = nums[0];
        for(int i=1; i<nums.size(); i++){
            curr_max = max(nums[i], curr_max + nums[i]);
            max_so_far = max(max_so_far, curr_max);
        }

        if(max_so_far <= 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << max_so_far << ".\n";
    }
    return 0;
}
