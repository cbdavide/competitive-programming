#include <bits/stdc++.h>
using namespace std;

int josephus(int n, int s) {
  if(n == 1)
    return 0;
  return (josephus(n - 1, s) + s) % n;
}

int main() {
  int n, p;

  while(cin >> n && n) {
    p = 0;
    
    while(josephus(n - 1, ++p) != 11){}

    cout << p << '\n';
  }  
  return 0;
}
