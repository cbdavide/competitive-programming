#include <bits/stdc++.h>
using namespace std;

int carry_count(string a, string b) {
  int cont = 0, carry = 0, t;
  
  int i = a.size() - 1;
  int j = b.size() - 1;
  for( ; i >=0 || j >= 0; i--, j--) {
    
    if(i < 0)
      t = b[j] - 48 + carry;
    else if(j < 0)
      t = a[i] - 48 + carry;
    else
      t = a[i] - 48 + b[j] - 48 + carry;

    if(t > 9) {
      cont++;
      carry = 1;
      t -= 10;
    } else {
      carry = 0;
    }
    
  }

  return cont;
}

int main() {
  string a, b;
  int r;

  while(cin >> a >> b && a[0] != '0' || b[0] != '0'){

    r = carry_count(a, b);

    if(!r)
      cout << "No carry operation.\n";      
    else if(r == 1)
      cout << r << " carry operation.\n";
    else
      cout << r << " carry operations.\n";

  }  
  return 0;
}
