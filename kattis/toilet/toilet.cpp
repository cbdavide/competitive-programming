#include <bits/stdc++.h>
using namespace std;

main() {
    int U, D, O;
    string input; 
       
    cin >> input;
    
    U = input[0] == 'D' ? 1 : input[1] == 'D' ? 2 : 0;
    D = input[0] == 'U' ? 1 : input[1] == 'U' ? 2 : 0;
    O = input[0] != input[1] ? 1 : 0;
    
    for(int i=2; i<input.size(); i++) {
        if(input[i] == 'D')
            U += 2;
        else
            D += 2;
        if(input[i] != input[i-1])
            O++;
    }
    
    cout << U << endl;
    cout << D << endl;
    cout << O << endl;
}