#include <bits/stdc++.h>
using namespace std;

typedef map<char, char> mcc;
typedef vector<mcc> mvcc;

int main() {
    string line;
    mvcc cans;
    while(true) {
        getline(cin, line);
        if(line == "#") break;
        else if(line[0] == 'e') {
            int maxi = 1e9, idx = 0, cont;
            for(int i=0; i<cans.size(); i++) {
                cont = 0;
                for(int j=0; j<cans.size(); j++) {
                    if(cans[i]['r'] != cans[j]['r']) cont++;
                    if(cans[i]['o'] != cans[j]['o']) cont++;
                    if(cans[i]['y'] != cans[j]['y']) cont++;
                    if(cans[i]['g'] != cans[j]['g']) cont++;
                    if(cans[i]['b'] != cans[j]['b']) cont++;
                }
                if(cont < maxi) {maxi = cont; idx = i; };
            }
            cout << idx + 1 << '\n';
            cans.clear();
        } else {
            mcc mapa;
            // cout << line << endl;
            for(int i=0; i<line.size(); ) {
                mapa[line[i]] = line[i + 2];
                // cout << line[i] << ' ' << line[i + 2] << endl;
                i += 4;
            }
            cans.push_back(mapa);
        }
    }
    return 0;
}
