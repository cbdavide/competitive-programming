#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums(3);
    string order;
    for(int i=0; i<3; i++)
        cin >> nums[i];
    cin >> order;
    sort(nums.begin(), nums.end());
    cout << nums[order[0] - 65] << ' '
         << nums[order[1] - 65] << ' '
         << nums[order[2] - 65] << '\n';
    return 0;
}
