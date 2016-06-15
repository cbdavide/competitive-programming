#include <bits/stdc++.h>
using namespace std;

int main() {
  int c, n, cont;
  char m;

  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> c;
    cont = 0;

    int h[c];
    for(int j=0; j<c; j++)
      cin >> h[j];

    for(int j=0; j<c; j++){
      cin >> m;

      if(m == 'S' && h[j] <= 2)
	cont++;
      else if(m == 'J' && h[j] > 2)
	cont++;
    }
    cout << cont << '\n';
  }
  return 0;
}
