#include <bits/stdc++.h>
using namespace std;

main() {
    
    int nTimes, amplitud, frecuency;
    cin >> nTimes;
    
    while(nTimes--) {
        
        cin >> amplitud;
        cin >> frecuency;
        
        for(int j=0; j<frecuency; j++) {
            
            for(int k=1; k<=amplitud; k++) {
                
              for(int l=1; l<=k; l++){
                  cout << k;
              }
              cout << '\n';  
            }
            
            for(int k=(amplitud -1); k>=1; k--) {
                
              for(int l=1; l<=k; l++){
                  cout << k;
              }
              cout << '\n';  
            }
            
            if( j != frecuency -1)
                cout << '\n';            
       }
       
       if(nTimes) {
           cout << '\n';
       }        
    }      
}