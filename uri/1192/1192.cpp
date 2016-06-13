#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, a, b, r;
  char c;

  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> a >> c >> b;

    if(a == b)
      r = a * b;
    else if(islower(c))
      r = a + b;
    else
      r = b - a;

    cout << r << '\n';
  }
  return 0;
}
