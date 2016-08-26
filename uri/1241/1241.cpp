#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, i;
  string a, b;

  cin >> t;
  while(t--){
    cin >> a >> b;
    i = b.size();
    
    if(a.size() >= b.size()) {
      
      if(a.substr(a.size() - i) == b)
        cout << "encaixa\n";
      else
        cout << "nao encaixa\n";

    } else
      cout << "nao encaixa\n";  
    
  }
  return 0;
}
