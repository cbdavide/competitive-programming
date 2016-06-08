#include <bits/stdc++.h>
using namespace std;

int n_factors(int n) {
  int cont = 0, root;

  while(n % 2 == 0) {
    cont++;
    n /= 2;
  }

  root = sqrt(n);
  for(int i=3; i<=root; i+=2) {
    while(n % i == 0){
      cont++;
      n /= i;
    }
  }

  if(n > 2)
    cont++;

  return cont;  
}

int main() {
  int n, num;
  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> num;
    if(n_factors(num) == 1)
      cout << "Prime\n";
    else
      cout << "Not Prime\n";
  }
  return 0;
}
