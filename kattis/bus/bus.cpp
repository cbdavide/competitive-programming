#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> s;
    cout << (long long)(pow(2, s) - 1) << '\n';
  }

  return 0;
}
