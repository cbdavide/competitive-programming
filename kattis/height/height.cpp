#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, k, s[20], cont, aux;
  cin >> n;

  for(int i=0; i<n; i++){
    cont = 0;
    cin >> k;

    for(int j=0; j<20; j++){
      cin >> s[j];
    }

    for(int l=0; l<20; l++){
      for(int m=l+1; m<20; m++){
	if(s[l] > s[m]){
	  aux = s[l];
	  s[l] = s[m];
	  s[m] = aux;
	  cont++;
	}
      }
    }
    cout << k << ' ' << cont << '\n';
  }
  
  return 0;
}
