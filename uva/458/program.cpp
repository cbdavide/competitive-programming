#include <iostream>
using namespace std;
main() {
  char prhase[1024];
  int i;
  while(cin >> prhase) {
    i = 0;
    while(prhase[i] != '\0') {
      prhase[i] = prhase[i] - 7;
      i++;
    }
    cout << prhase << endl;
  }
}
