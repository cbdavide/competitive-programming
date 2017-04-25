#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<char, vi> mcvi;

int main() {
    int t, cont, ini;
    char c, d;
    bool cond;
    string line;
    mcvi mapa;

    cin >> line >> t;

    for(int i=0; i<line.size(); i++)
        mapa[line[i]].push_back(i);

    while(t--) {
        cont = -1;
        cond = true;
        cin >> line;

        for(int i=0; i<line.size(); i++) {
            c = line[i];

            vi::iterator itr = lower_bound(mapa[c].begin(), mapa[c].end(), cont + 1);
            cont = *itr;
            if(itr == mapa[c].end()) {
                cond = false;
                break;
            }
        }
        if(!cond) printf("Not matched\n");
        else {
            c = line[0]; d = line[line.size() - 1];
            vi::iterator ini = lower_bound(mapa[c].begin(), mapa[c].begin(), 0);
            printf("Matched %d %d\n", *ini, cont);
        }
    }
    return 0;
}
