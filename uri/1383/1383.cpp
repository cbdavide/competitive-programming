#include <bits/stdc++.h>
using namespace std;

bool veryfy_row(int mat[9][9], int row){
  set<int> s;

  for(int i=0; i<9; i++)
    s.insert(mat[row][i]);

  return s.size() == 9;
}

bool verify_column(int mat[9][9], int column){
  set<int> s;

  for(int i=0; i<9; i++)
    s.insert(mat[i][column]);

  return s.size() == 9;
}

bool verify_block(int mat[9][9], int r_from, int r_to, int c_from, int c_to) {
  set<int> s;

  for(int i=r_from; i<=r_to; i++){
    for(int j=c_from; j<=c_to; j++)
      s.insert(mat[i][j]);
  }

  return s.size() == 9;
}

int main() {
  int t, val[3][2] = {{0, 2}, {3, 5}, {6, 8}};
  bool cond;

  cin >> t;
  for(int a=0; a<t; a++) {
    int mat[9][9];
    cond = true;

    for(int i=0; i<9; i++) {//Reading the sudoku
      for(int j=0; j<9; j++){
        cin >> mat[i][j];
      }
    }

    for(int i=0; i<9; i++) {//Verify all the rows
      if(!veryfy_row(mat, i)) {
        cond = false;
        break;
      }
    }

    if(cond){//Verify all the columns
      for(int i=0; i<9; i++) {
        if(!verify_column(mat, i)) {
          cond = false;
          break;
        }
      }
    }

    if(cond) {//Verify all the blocks

      for(int k=0; k<3; k++) {
        for(int i=0; i<3; i++){
          if(!verify_block(mat, val[k][0], val[k][1], val[i][0], val[i][1])){
            cond = 0;
            break;
          }
        }
      }
    }

    cout << "Instancia " << (a + 1) << '\n';
    if(cond)
      cout << "SIM\n\n";
    else
      cout << "NAO\n\n";

  }
  return 0;
}
