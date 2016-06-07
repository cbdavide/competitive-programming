#include <iostream>
using namespace std;

int main() {
  int t, a;
  string s;

  cin >> t >> a;
  for(int i=0; i<a; i++){
    cin >> s;

    if(s == "fechou")
      t++;
    else
      t--;
  }
  cout << t << '\n';
  return 0;
}
