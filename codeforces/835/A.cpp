#include <bits/stdc++.h>
using namespace std;

typedef map<char, int> mci;
typedef map<char, bool> mcb;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int answ1 = (2 * t1) + (s * v1);
    int answ2 = (2 * t2) + (s * v2);
    // cout << answ1 << ' ' << answ2 << endl;
    if(answ1 == answ2) cout << "Friendship\n";
    else if(answ1 < answ2) cout << "First\n";
    else cout << "Second\n";
    return 0;
}
