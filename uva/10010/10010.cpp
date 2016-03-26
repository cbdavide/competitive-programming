#include <bits/stdc++.h>
using namespace std;

bool search(string* mat, int n, int m, int posI, int posJ, int dirI, int dirJ, string word) {
    int i = posI, j = posJ, k = 0;    
    for(; (i<n && i >= 0) && (j<m && j >= 0) && k < word.size(); i += dirI, j+=dirJ, k++) {
        if(tolower(word[k]) != tolower(mat[i][j]))
            return false;
    }
    if(k == word.size())
        return true;
        
    return false;    
}

main() {
    int dir[8][2] = {{1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1},
                     {0,1}, {1,1}, {1,0}};
    int nCases, nRows, nCols, nWords;
    string *rows, word;  
    
    cin >> nCases;
    
    for(int i=0; i<nCases; i++) {
        cin >> nRows >> nCols;
        rows = new string[nRows];
        
        for(int j=0; j<nRows; j++) {//Reading the lines
            cin >> rows[j];
        }
        
        cin >> nWords;
        for(int j=0; j<nWords; j++) {//Iteration per word
            cin >> word;
            for(int ii=0; ii<nRows; ii++) {
                for(int jj=0; jj<nCols; jj++) {
                    
                    if(tolower(word[0]) == tolower(rows[ii][jj])) {
                        for(int z=0; z<8; z++) {
                            if(search(rows, nRows, nCols, ii, jj, dir[z][0], dir[z][1], word)){
                                cout << ii+1 << " " << jj+1 << endl;
                                z = 8; ii = nRows; jj = nCols;
                            }
                        }
                    }
                }
            }
        }
        if(i != nCases -1)
            cout << "\n";                
    }
}