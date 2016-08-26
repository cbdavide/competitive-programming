#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, i;
  string a, b, c;

  cin >> n;
  while(n--){
     c = "";
     cin >> a >> b;

     for(i=0; i<a.size() && i<b.size(); i++) {
       c += a[i];
       c += b[i];
     }

     if(i < a.size())
       c += a.substr(i);
     else
       c += b.substr(i);

     cout << c << endl;
  }
  return 0;
}
