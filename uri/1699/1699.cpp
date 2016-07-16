#include <bits/stdc++.h>
using namespace std;

bool perfectSquare(double d) {
  d = sqrt(d);
  return (double)(d - (int)d) == 0;
}

int main() {
  int n, total;
  double t;

  while(cin >> n && n) {
    total = 0;

    for(int i=0; i<n; i++){
      cin >> t;
      total += perfectSquare(t) ? 1 : 2;
    }

    if(total % 2 == 0)
      cout << "Garen\n";
    else
      cout << "Annie\n";
    
  }
  return 0;
}
