#include <bits/stdc++.h>
using namespace std;

bool is_lineal(int x, int y, int a, int b) {
  return x == a || y == b;
}

bool is_diagonal(int x, int y, int a, int b){
  return x + y == a + b || x + b == y + a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int x, y, a, b;

  while(cin >> x >> y >> a >> b && (x + y + a + b)) {

    if(x == a && y == b)
      cout << "0\n";
    else if(is_lineal(x, y, a, b) || is_diagonal(x, y, a, b))
      cout << "1\n";
    else
      cout << "2\n";

  }  
  return 0;
}
