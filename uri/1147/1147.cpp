#include <bits/stdc++.h>
using namespace std;

bool is_valid(bool arr[8][8], int r, int c){
  return (r >= 0 && r <= 7) && (c >= 0 && c <= 7);
}

int main() {

  int move[8][2] = {{-1, -2}, {1, -2}, {1, 2}, {-1, 2},
		    {-2, -1}, {2, -1}, {2, 1}, {-2, 1}};

  int kr, tr, cont, k = 0;
  char kc, tc;

  while(cin >> kr && kr){
    cin >> kc;
    cont = 0;

    bool board[8][8];
    memset(board, 1, 64);

    for(int i=0; i<8; i++) {
      cin >> tr >> tc;

      //Filling the attack positions of the pawns
      if(is_valid(board, tr - 2, tc - 98))
	board[tr - 2][tc - 98] = 0;

      if(is_valid(board, tr - 2, tc - 96))
	board[tr - 2][tc - 96] = 0;

    }

    for(int i=0; i<8; i++) {
      int r = kr -1, c = kc - 97;

      if(is_valid(board, r + move[i][0], c + move[i][1])){
	if(board[r + move[i][0]][c + move[i][1]])
	  cont++;
      }
      
    }

    cout << "Caso de Teste #" << ++k <<": "
	 << cont << " movimento(s).\n";
  }
  
  return 0;
}
