#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, b, e, cont;
  string c;

  cin >> n;

  for(int i=0; i<n; i++){
    
    cont = 0;
    cin >> c;

    b = c.find_first_of('<', 0);
    e = c.find_first_of('>', 0);

    while(b != string::npos && e != string::npos) {

      if(b >= 0 &&  b < e){
	c[b] = '.';
	b = c.find_first_of('<', b + 1);

	cont++;
      }

      c[e] = '.';      
      e = c.find_first_of('>', e + 1);
    }
    
    cout << cont << '\n';
  }
  
  return 0;
}
