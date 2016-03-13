#include <bits/stdc++.h>
using namespace std;

main() {
    int nCases, state;
    string line = "";
    string dist[10] = {
       " ", "", "abc", "def", "ghi", "jkl",
       "mno", "pqrs", "tuv", "wxyz"
    };
    
    cin >> nCases;
    getline(cin, line);
    
    for(int i=0; i<nCases; i++) {
        state = -1;
        getline(cin, line);
        cout << "Case #" << i+1 << ": ";
        for(int j=0; j<line.size(); j++) {
            for(int k=0; k<10; k++) {
                for(int z=0; z<dist[k].size(); z++) {
                    
                    if(line[j] == dist[k][z]) {
                        if(state == k)
                            cout << " ";
                        for(int x=0; x<=z; x++) 
                            cout << k;
                        state = k;
                    }
                }
            }
        }
        cout << '\n';        
    }    
}