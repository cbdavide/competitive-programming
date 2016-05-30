#include <bits/stdc++.h>
using namespace std;

int main() {

    int r, n, temp, i;
    bool *rooms, cond = true;

    cin >> r >> n;

    rooms = new bool[r];
    memset(rooms, 0, r);

    for(i = 0; i < n; i++) {
        cin >> temp;
        rooms[--temp] = 1;
    }

    for(i = 0; i < r; i++) {
        if(!rooms[i]) {
            cond = false;
            break;
        }
    }

    if(cond)
        cout << "too late\n";
    else
        cout << ++i << '\n';

    return 0;
}
