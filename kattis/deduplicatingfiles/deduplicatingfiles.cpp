#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef set<string> sstring;
typedef map<int, vs> mivs;
typedef map<int, sstring> misstring;

int hashi(string line) {
    int h = 0;

    for(int i=0; i<line.size(); i++)
        h ^= line[i];

    return h;
}

int process(vs arr) {
    int answ = 0;

    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i] != arr[j])
                answ++;
        }
    }

    return answ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t, h, collisions, unrepeated;
    string line;

    while(cin >> t && t) {
        getline(cin, line);

        mivs dc;
        misstring odc;
        for(int i=0; i<t; i++) {
            getline(cin, line);

            h = hashi(line);
            dc[h].push_back(line);
            odc[h].insert(line);
        }

        collisions = unrepeated = 0;
        mivs::iterator itr = dc.begin();
        for( ; itr != dc.end(); itr++) {
            int key = (*itr).first;
            unrepeated += odc[key].size();
            collisions += process((*itr).second);
        }

        cout << unrepeated << ' ' << collisions << '\n';
    }
    return 0;
}
