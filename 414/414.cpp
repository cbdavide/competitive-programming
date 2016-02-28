#include <bits/stdc++.h>
using namespace std;

main() {
    int nCases, minSpaces, totalSpaces;
    string line;
    
    while(cin >> nCases && nCases != 0){
        cin.ignore();
        vector<int> nSpaces(nCases);
        minSpaces = 100;
        totalSpaces = 0;
        for(int i=0; i<nCases; i++){
            int cont = 0;
            getline(cin, line);
            for(int j=0; j<25; j++) {
                if(line[j] == ' ')
                    cont++;
            }
            nSpaces[i] = cont;
            if(nSpaces[i] < minSpaces)
                minSpaces = nSpaces[i];
        }
        for(int i=0; i<nCases; i++) {
            totalSpaces += nSpaces[i] - minSpaces;
        }
        cout << totalSpaces << endl;
    }       
}