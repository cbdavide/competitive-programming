#include <bits/stdc++.h>
using namespace std;

typedef map<string, string> mss;

int main() {
    int t;
    cin >> t;
    
    string line, line2, animal, goes, sound;
    getline(cin, line);

    while(t--) {
        mss T;
        vector<string> vs;
        getline(cin, line);
        while(getline(cin, line2) && line2 != "what does the fox say?") {
            stringstream ss(line2);
            ss >> animal >> goes >> sound;
            T[sound] = animal;
        }
        stringstream ss(line);
        while(ss >> sound)
            if(T[sound].empty()) vs.push_back(sound);
       for(int i=0; i<vs.size(); i++) {
            if(i) cout << ' ';
            cout << vs[i];
       }
       cout << endl;
    }
    return 0;
}
