#include <bits/stdc++.h>
using namespace std;

int main() {
  char day[] = {'D', 'L', 'M', 'X', 'J', 'V', 'S'};
  int n, y, m, d, cont, t;
  cin >> n;

  for(int i=0; i<n; i++){
    cont = d = 0;
    cin >> y >> m;

    for(int j=0; j<m; j++) {
      cin >> t;

      if(t >= 13){
	if(day[(d + 13 - 1) % 7] == 'V')
	  cont++;
      }

      d += t;
    }
    
    cout << cont << '\n';
  }
 
  return 0;
}
