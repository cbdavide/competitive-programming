#include <bits/stdc++.h>
using namespace std;

main() {
    
    int nCases, dna[10];
    char code[] = {' ', '.', 'x', 'W'};
    
    cin >> nCases;
    
    for(int i=0; i<nCases; i++) {
        vector <int> today(40);
        vector <int> tomorrow(40);
        today[19] = 1;
        
        for(int j=0; j<10; j++) {
            cin >> dna[j];
        }
        
        for(int k=0; k<50; k++) {
            tomorrow[0] = 0 + today[0] + today[1];
            tomorrow[39] = today[38] + today[39] + 0;
            
            for(int j=1; j<39; j++) {
                tomorrow[j] = today[j-1] + today[j] + today[j+1];
            }
            
            for(int j=0; j<40; j++) {
                cout << code[today[j]];                
                today[j] = dna[tomorrow[j]];
            }
            cout << '\n';     
        }
        if(i < nCases-1)
            cout << '\n';          
    }    
}