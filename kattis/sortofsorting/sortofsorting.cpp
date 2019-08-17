#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> si;
typedef vector<si> vsi;

bool cmp(si &a, si &b) {
    if((a.first)[0]  == (b.first)[0]){
        if((a.first)[1] == (b.first)[1])
            return a.second < b.second;
        return (a.first)[1] < (b.first)[1];
    } 
    return (a.first)[0] < (b.first)[0];
}

int main() {
    int z=0, t;
    while(cin >> t && t) {
        if(z++) cout << endl;
        
        vsi T(t);
        for(int i=0; i<t; i++) {
            cin >> T[i].first;
            T[i].second = i;
        }

        sort(T.begin(), T.end(), cmp);
        for(auto p : T) cout << p.first << endl;
    }
    return 0;
}
