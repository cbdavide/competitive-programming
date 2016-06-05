#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t, *dvd, cont, a;

  cin >> n;
  for(int i=0; i<n; i++){
    cont = 0;
    cin >> t;
    dvd = new int[t+1];
    
    for(int j=1; j<=t; j++)
      cin >> dvd[j];

    a = 1;
    for(int j=1; j<=t; j++){
      if(dvd[j] == a)
	a++;
      else
	cont++;
    }
    cout << cont << '\n';
  }
  return 0;
}
