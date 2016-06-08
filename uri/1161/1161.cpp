#include <bits/stdc++.h>
using namespace std;

unsigned long long factorial(int n) {
  if(n == 0 || n == 1)
    return 1;
  
  return n * factorial(n - 1);
}

int main() {
  int a, b;
  while(cin >> a >> b)
    cout << factorial(a) + factorial(b) << '\n';
  return 0;
}
