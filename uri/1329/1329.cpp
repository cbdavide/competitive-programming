#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, m, j;
  bool t;
  
  while(cin >> n && n) {
    m = j = 0;
    
    for(int i=0; i<n; i++){
      cin >> t;

      if(t)
	j++;
      else
	m++;	
    }
    cout << "Mary won " << m << " times and John won "
	 << j << " times\n";
  }
  return 0;
}
