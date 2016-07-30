#include <bits/stdc++.h>
using namespace std;

int main() {
  int c, n, m, x, y, calc;

  cin >> c;
  for(int i=0; i<c; i++){
    cin >> n >> m >> x >> y;

    x--;
    y--;

    int matrix[n][m];
    for(int j=0; j<n; j++){
      for(int k=0; k<m; k++) {
	cin >> matrix[j][k];
      }
    }

    cout << "Parede " << (i + 1) << ":\n";

    for(int j=0; j<n; j++) {
      for(int k=0; k<m; k++){
	
	calc = 10 - max(abs(j - x), abs(k - y));
	matrix[j][k] += (calc > 0) ? calc : 1;

	cout << matrix[j][k];

	if(k < m - 1)
	  cout << ' ';
      }
      cout << '\n';
    }
    
  }
  return 0;
}
