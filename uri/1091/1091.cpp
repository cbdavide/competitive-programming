#include<bits/stdc++.h>
using namespace std;

int main() {
  int k, x, y, n, m;

  while(cin >> k && k) {
    cin >> x >> y;

    for(int i=0; i<k; i++){
      cin >> n >> m;

      if(x == n || y == m)
	cout << "divisa\n";
      else if(n > x && m > y)
	cout << "NE\n";
      else if(n > x && m < y)
	cout << "SE\n";
      else if(n < x && m > y)
	cout << "NO\n";
      else
	cout << "SO\n";
      
    }
  }
  return 0;
}
