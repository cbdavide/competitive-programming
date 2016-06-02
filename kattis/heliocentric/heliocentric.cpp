#include <iostream>
using namespace std;

int main() {
  int e, m, cont, i = 0;
  
  while(cin >> e >> m) {
    cont = 0;

    while(e  % 365 != 0 || m % 687 != 0){
      e++;
      m++;
      cont++;
    }

    cout << "Case " << ++i << ": " << cont << '\n';
    
  }
  return 0;
}
