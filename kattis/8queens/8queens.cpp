#include <bits/stdc++.h>
using namespace std;

string board[8];
bool matchA(int i, int j, int dirI, int dirJ) {
    int cont = 0;
    for(; i<8 && j<8; i+=dirI, j+= dirJ) {
        if(board[i][j] == '*')
            cont++;
    }
    return cont > 1;
}

main() {
    int nQueens = 0;
    string answer = "valid";
    int dir[4][2] = {{0,1}, {1,0}, {1,1}, {1,-1}};
    
    for(int i=0; i<8; i++)
        cin >> board[i];
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            
            if(board[i][j] == '*') {
                nQueens++;
                for(int k=0; k<4; k++) {
                    if(matchA(i, j, dir[k][0], dir[k][1])){
                        i = 8; j = 8; k = 4;
                        answer = "invalid";
                    }
                }
            }
        }
    }
    if(nQueens != 8)
        answer = "invalid";
        
    cout << answer << endl;    
}