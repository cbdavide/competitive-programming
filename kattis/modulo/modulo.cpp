#include <bits/stdc++.h>
using namespace std;

int main() {

  int t;
  map<int , int> digits;

  for(int i=0; i<10; i++) {
    cin >> t;
    digits[t % 42]++;
  }
  cout << digits.size() << '\n';
  return 0;
}
