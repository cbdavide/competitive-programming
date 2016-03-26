#include <bits/stdc++.h>
using namespace std;

bool color(int r, char c){
    return (r + c) % 2;
}

bool valid(int r, char c) {
    return (r >= 1 && r <= 8) && (c >= 'A' && c <= 'H');
}

bool diagonal(int r1, char c1, int r2, char c2) {
    return (r1 + c1 == r2 + c2) || (r1 + c2 == c1 + r2);
}

main() {
    int nCases, r1, r2;
    char c1, c2;
    
    cin >> nCases;
    
    for(int i=0; i<nCases; i++) {
        
        cin >> c1 >> r1 >> c2 >> r2;
        
        if(color(r1, c1) != color(r2, c2)) {
            cout << "Impossible\n";
        } else if(r1 == r2 && c1 == c2) {
            cout << "0 " << c1 << " " << r1 << '\n';
        } else if(diagonal(r1, c1, r2, c2)) {
            cout << "1 " << c1 << " " << r1 << " " << c2 << " " << r2 << '\n';
        } else {
            int rI;
            char cI;
            
            rI = (r2 + c2 + r1 - c1) / 2;
            cI = (r2 + c2 - r1 + c1) / 2;
            
            if(!valid(rI, cI)) {
                rI = (r1 + c1 + r2 - c2)/2;
                cI = (r1 + c1 - r2 + c2)/2;
            }
            
            cout << "2 " << c1 << " " << r1
                 << " " << cI << " " << rI
                 << " " << c2 << " " << r2 << '\n';                    
        }          
    }    
}