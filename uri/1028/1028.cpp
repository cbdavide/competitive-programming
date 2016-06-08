#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  int r;
  while(b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b;
  cin >> n;
  
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    cout << gcd(max(a, b), min(a, b)) << '\n';
  }
  
  return 0;
}
