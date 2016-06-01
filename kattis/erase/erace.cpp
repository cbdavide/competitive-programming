#include <bits/stdc++.h>
using namespace std;

char rewrite(char c, bool is_even){
  if(is_even)
    return c;
  else
    return c == '1'? '0' : '1';
}

int main(){

  int n;
  string b, a;
  bool cond = true;

  cin >> n >> b >> a;

  for(int i=0; i<b.size(); i++){

    if(rewrite(b[i], n % 2 == 0) != a[i]){
      cond = false;
      break;
    }
  }

  if(cond)
    cout << "Deletion succeeded\n";
  else
    cout << "Deletion failed\n";
  
  return 0;
}
