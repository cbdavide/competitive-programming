#include <bits/stdc++.h>
using namespace std;

int moves[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int select(char c) {
  if(c == 'R')
    return 0;
  if(c == 'U')
    return 1;
  if(c == 'L')
    return 2;
  if(c == 'D')
    return 3;
}

int main() {
  int n, m, q, x, y, f, cont;
  char move;
  string def;

  while(cin >> n >> m >> q && (n + m + q)){
    getline(cin, def);
    cont = 0;
    string board[n];

    for(int i=0; i<n; i++) {
      getline(cin, board[i]);

      f = board[i].find('<');

      if(f != string::npos){
	x = i;
	y = f;
      }
    }

    f = select('R');
    for(int i=0; i<q; i++) {
      cin >> move;

      if(move != 'W'){
	f = select(move);//Changes the direction
      } else {
	int xx = (x + moves[f][0]);
	int yy = (y + moves[f][1]);

	if(board[xx][yy] == '*'){

	  cont++;
	  board[x][y] = ' ';
	  board[xx][yy] = '<';

	  x = xx;
	  y = yy;
	} else if (board[xx][yy] == ' '){
	  board[x][y] = ' ';
	  board[xx][yy] = '<';

	  x = xx;
	  y = yy;
	}
      }
    }
    cout << cont << '\n';
  }
  return 0;
}
