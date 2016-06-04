#include <bits/stdc++.h>
using namespace std;

int main() {

  int a, b, c, d, i = 0, det;

  while(cin >> a >> b >> c >> d) {

    det = (a * d) - (b * c);

    a /= det;
    d /= det;
    b = (b * -1) / det;
    c = (c * -1) / det;

    cout << "Case " << ++i << ":\n";
    cout << d << ' ' << b << '\n';
    cout << c << ' ' << a << '\n';
    
  }
  
  return 0;
}
