#include <bits/stdc++.h>
using namespace std;

char braile[10][6] = {{'.', '*', '*', '*', '.', '.'}, // 0
		      {'*', '.', '.', '.', '.', '.'}, // 1
		      {'*', '.', '*', '.', '.', '.'}, // 2
		      {'*', '*', '.', '.', '.', '.'}, // 3
		      {'*', '*', '.', '*', '.', '.'}, // 4
		      {'*', '.', '.', '*', '.', '.'}, // 5
		      {'*', '*', '*', '.', '.', '.'}, // 6
		      {'*', '*', '*', '*', '.', '.'}, // 7
		      {'*', '.', '*', '*', '.', '.'}, // 8
		      {'.', '*', '*', '.', '.', '.'}};// 9

void printDecimals(string line){
  for(int i=0; i<3; i++){

    for(int j=0; j<line.size(); j++){
      cout << braile[line[j] - '0'][2*i]
	   << braile[line[j] - '0'][2*i + 1];

      if(j < line.size() - 1)
	cout << ' ';
    }
    cout << '\n';
  }
};

void printBraile(int n) {
  int i, j, k;
  char digit[n][6];
  bool cond;

  for(i=0; i<3; i++) {
    for(j=0; j<n; j++){
      cin >> digit[j][2*i] >> digit[j][2*i + 1];
    }
  }

  for(i=0; i<n; i++) {

    for(j=0; j<10; j++){
      cond = true;

      for(k=0; k<6; k++) {
	
	if(digit[i][k] != braile[j][k]){
	  cond = false;
	  k = 6;
	}
      }
      
      if(cond) {
	cout << j;
	j = 10;
      }      
    }
  }
  cout << '\n';
}

int main() {

  int n;
  char s;
  string line;

  while(cin >> n && n){
    cin >> s;

    if(s == 'S') {
      cin >> line;
      printDecimals(line);
    } else {
      printBraile(n);
    } 

  }
  return 0;
}
