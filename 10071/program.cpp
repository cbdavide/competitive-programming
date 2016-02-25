#include <iostream>
using namespace std;
main() {
  int v, t;
  while( cin >> v && cin >> t){
    if((v >= -100 && v <= 100) && (t >= 0 && t <= 200))
    cout << 2*v*t << endl;
  }
}
