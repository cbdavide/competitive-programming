#include <bits/stdc++.h>
using namespace std;

main() {

    string line;
    int bleed, total;
    char c;

    getline(cin, line);
    getline(cin, line);
    while(line[0] != '_') {
        bleed = 0;
        total = 0;
        for(int i=9, j=0; i>0; i--,j++) {
            if(line[i] == 'o') {
                total += pow(2, j-bleed);
            } else if(line[i] == '.') {
                bleed++;
            }
        }
        c = total;
        if(total == 10 || total == 13) {
            cout << '\n';
        } else if(total != 8){
            cout << c;
        }

        getline(cin, line);
    }
}
