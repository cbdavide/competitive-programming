#include <bits/stdc++.h>
using namespace std;

typedef map<char, int> mci;
typedef map<char, bool> mcb;

int main() {
    int n, k, guards = 0;
    string guest;
    bool cond = true;

    cin >> n >> k;
    cin >> guest;

    mci begin, end; mcb open;

    for(int i=0; i<guest.size(); i++) {
        if(!open[guest[i]]) {
            begin[guest[i]] = i;
            end[guest[i]] = i;
            open[guest[i]] = true;
        } else {
            end[guest[i]] = i;
        }
    }
    for(int i=0; i<guest.size(); i++) {
        if(begin[guest[i]] == i) guards++;
        if(guards > k) {
            cond = false;
            break;
        }
        if(end[guest[i]] == i) guards--;
    }
    if(!cond) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
