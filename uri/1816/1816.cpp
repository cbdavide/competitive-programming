#include <bits/stdc++.h>
using namespace std;

int main() {
  string cad = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", copy;
  int n, k, h = 0;

  while(cin >> n && n){
    copy = cad;

    cout << "Instancia " << ++h << '\n';
    for(int i=0; i<n; i++){
      cin >> k;
      cout << copy[k - 1];
      copy.insert(copy.begin(), copy[k - 1]);
      copy.erase(copy.begin() + k);
    }
    cout << "\n\n";
  }
  return 0;
}
