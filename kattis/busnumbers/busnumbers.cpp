#include <bits/stdc++.h>
using namespace std;

int times(vector<int> bus, int index) {
    int j, i = index;
    for(i = index+1, j=1; i<bus.size(); i++, j++) {
        if(bus[index]+j != bus[i]){
            i;
            break;
        }
    }
    return --i;
}

main() {
    int n, temp, j, ntimes;
    vector<int> busses;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> temp;
        busses.push_back(temp);
    }

    sort(busses.begin(), busses.end());

    for(int i=0; i<busses.size(); i++) {
        ntimes = times(busses, i);

        if(ntimes - i < 2){
            cout << busses[i];
        } else if( ntimes - i >= 2) {
            cout << busses[i] << '-' << busses[ntimes];
            i = ntimes;
        }

        if(i < busses.size() - 1)
            cout << ' ';
    }
    cout << '\n';
}
