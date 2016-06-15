#include <bits/stdc++.h>
using namespace std;

int main() {
  int note[7] = {100, 50, 20, 10, 5, 2, 1};
  int answ[7] = {0, 0, 0, 0, 0, 0, 0};
  int n, copy;

  cin >> n;
  copy = n;

  for(int i=0; i<7; i++) {
    answ[i] = n / note[i];
    n %= note[i];
  }

  cout << copy << '\n';
  for(int i=0; i<7; i++)
    cout << answ[i] << " nota(s) de R$ " << note[i] << ",00\n";
  
  return 0;
}
