#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  double d;

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> d;

    cout << ceil(log2(d)) << " dias\n";
  }
  return 0;
}
