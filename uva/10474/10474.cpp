#include <bits/stdc++.h>
using namespace std;

int find(vector<int> arr, int val) {
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == val)
            return i;
    }
    return -1;
}

main() {
    int nmarbles, nquerys, query, index, k=1;

    while(cin >> nmarbles >> nquerys && nmarbles && nquerys) {
        vector<int>marbles(nmarbles);
        for(int i=0; i<nmarbles; i++) {
            cin >> marbles[i];
        }
        sort(marbles.begin(), marbles.end());//Array sorted.
        cout << "CASE# " << k++ << ":\n";
        for(int i=0; i<nquerys; i++) {
            cin >> query;
            index = find(marbles, query);
            if(index != -1) {
                cout << query << " found at " << index+1 << '\n';
            } else {
                cout << query << " not found" << '\n';
            }
        }
    }
}
