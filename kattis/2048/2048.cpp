#include <bits/stdc++.h>
using namespace std;

void move(int mat[4]) {
    for(int i=0; i<4; i++) {
        if(mat[i] == 0) {
            for(int j=i+1; j<4; j++){
                if(mat[j] != 0) {
                    mat[i] = mat[j];
                    mat[j] = 0;
                    j = 4;
                }
            }
        }
    }
}

void operate(int mat[4]) {
    for(int i=1; i<4; i++){
        if(mat[i-1] == mat[i]) {
            mat[i-1] *= 2;
            mat[i] = 0;
        }
    }
}

int *columnToArray(int mat[4][4], int posI, int dir, int c) {
    int *array = new int[4];
    for(int i=0, j=posI; i<4 && j>=0 && j<4; i++, j+=dir){
        array[i] = mat[j][c];
    }
    return array;
}

void arrayToColumn(int mat[4][4], int arr[4], int posI, int dir, int c){
    for(int i=posI, j=0; i<4 && i>=0 && j<4; i+=dir, j++) {
        mat[i][c] = arr[j];
    }
}

int *inverseRowToArray(int row[4]){
    int *rowInverse = new int[4];
    for(int i=0, j=3; i<4 && j>=0; i++, j--) {
        rowInverse[i] = row[j];
    }
    return rowInverse;
}

void arrayToRow(int mat[4][4], int row[4], int r) {
    for(int i=3, j=0; i>=0 && j<4; i--, j++) {
        mat[r][j] = row[i];
    }
}

main() {
    int mat[4][4], paso[4][4], flow;
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++){
            cin >> mat[i][j];
        }
    }
    cin >> flow;
    
    switch(flow){
        case 0:
            for(int i=0; i<4; i++) {
                move(mat[i]);
                operate(mat[i]);
                move(mat[i]);
            }
            break;
        case 1:
            for(int i=0; i<4; i++) {
                int *arra = columnToArray(mat, 0, 1, i);
                move(arra);
                operate(arra);
                move(arra);
                arrayToColumn(mat, arra, 0, 1, i);
            }        
            break;
        case 2:
            for(int i=0; i<4; i++) {
                int *arra = inverseRowToArray(mat[i]);
                move(arra);
                operate(arra);
                move(arra);
                arrayToRow(mat, arra, i);
            }
            break;
        case 3:
            for(int i=0; i<4; i++) {
                int *arra = columnToArray(mat, 3, -1, i);
                move(arra);
                operate(arra);
                move(arra);
                arrayToColumn(mat, arra, 3, -1, i);
            } 
            break;
    }

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++){
            cout <<  mat[i][j] << ' ';
        }
        cout << endl ;
    }
}