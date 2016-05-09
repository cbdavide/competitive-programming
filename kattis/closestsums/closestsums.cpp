#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int> v, int val) {
    int closest = v[0];
    for(int i = 0; i<v.size(); i++) {
        if(abs(val - v[i]) < abs(val - closest))
            closest = v[i];
    }
    return closest;
}

main() {

    int n, q, t, c, cont = 0;

    while(cin >> n) {
        vector<int> sums;
        int nums[n];

        for(int i=0; i<n; i++)
            cin >> nums[i];

        for(int i=0; i<n; i++) {
            for(int j= i+1; j<n; j++) {
                sums.push_back(nums[i] + nums[j]);
            }
        }

        cout << "Case " << ++cont << ":\n";
        cin >> q;
        for(int i = 0; i < q; i++) {
            cin >> t;
            c = find(sums, t);
            cout << "Closest sum to " << t << " is " << c << ".\n";
        }

    }
}
