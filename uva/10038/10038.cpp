#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, e) for(int i=s; i<e; i++)

typedef vector<int> vi;
typedef vector<bool> vb;

bool check(vi &nums) {
    vb cond(nums.size());
    rep(i, 0, nums.size() - 1) {
        int val = abs(nums[i] - nums[i + 1]);
        if(val < nums.size())
            cond[val] = true;
    }
    rep(i, 1, cond.size())
        if(!cond[i]) return false;
    return true;
}

int main() {
    int n;
    while(cin >> n) {
        vi nums(n);
        rep(i, 0, n) cin >> nums[i];
        if(check(nums)) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}
