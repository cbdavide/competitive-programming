#include <bits/stdc++.h>
using namespace std;

main() {    
    string lines[105];
    int index = 0;
    int length = 0;
       
    while(getline(cin, lines[index])){
        if(lines[index].size() > length)
            length = lines[index].size();
        index++;
   }
    
    for(int j=0; j<length; j++){//charAt
        for(int i=(index-1); i>=0; i--){//Line
            if(lines[i].size() > j){
                cout << lines[i][j];
            }else{
                cout << ' '; 
            }
        }
        cout << '\n';            
    }   
}