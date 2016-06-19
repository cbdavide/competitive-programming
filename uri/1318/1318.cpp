#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  int n, p, t, cont;

  while(cin >> n >> p && (n + p)){
    vi tickets(n, 0);
    cont = 0;
    
    for(int i=0; i<p; i++){
      cin >> t;
      tickets[t - 1]++;      
    }

    for(int i=0; i<n; i++) {
      if(tickets[i] > 1)
	cont++;
    }
    
    cout << cont << '\n';
  }
  return 0;
}

