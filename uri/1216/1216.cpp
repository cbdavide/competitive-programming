#include<bits/stdc++.h>
using namespace std;

int main() {
  string name, empty;
  int d = 0, di, i = 0;
  double answ;

  while(getline(cin, name)) {
    cin >> di;
    getline(cin, name);
    d += di;
    i++;
  }

  answ = d / (double)i;
  
  printf("%.1f\n", answ);
  return 0;
}
