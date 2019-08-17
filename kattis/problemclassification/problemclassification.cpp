#include <bits/stdc++.h>
using namespace std;

typedef set<string> si;
typedef map<string, int> mi;
typedef map<string, si> msi;

int main() {

    mi T;
    msi C;
    int n, t;
    string name, word;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> name >> t;
        for(int j=0; j<t; j++) {
            cin >> word;
            C[name].insert(word);
        }
    }

    while(cin >> word){
        for(auto category : C){
            if(category.second.count(word))
                T[category.first]++;
        }
    }

    vector<pair<int, string> > R;
    for(auto p : T) R.push_back({p.second, p.first});
    sort(R.rbegin(), R.rend());
    
    vector<string> O;

    if(R.empty()){
        for(auto c : C) cout << c.first <<  endl;
        return 0;
    }

    int idx = 0;
    while(idx < R.size() && R[idx].first == R[0].first)
        O.push_back(R[idx++].second);

    sort(O.begin(), O.end());
    for(string s : O) cout << s << endl;
    return 0;
}

