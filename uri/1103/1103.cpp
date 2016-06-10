#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, m, i, o, r;
  while(cin >> h >> m >> i >> o && (h + m + i + o)){

    r = ((i * 60) + o) - ((h * 60) + m);
    
    if(r < 0)
      r = (24 * 60) + r;

    cout << r << '\n';

  }
  return 0;
}
