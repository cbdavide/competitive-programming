#include <bits/stdc++.h>
using namespace std;

typedef multiset<int> ml;

int main() {
  int m, f, aux, a, b;
  ml::iterator k;

  while(cin >> m >> f){
    ml mices;
    
    for(int i=0; i<m; i++){
      cin >> aux;
      mices.insert(aux);
    }

    for(int i=0; i<f; i++) {
      cin >> aux;

      if(mices.size()) {
	
	if(aux < (*mices.begin())){
	  
	  k = mices.end();
	  k--;
	  mices.insert((*k) - aux);
	  mices.erase(k);
	  
	} else {
	  
	  k = mices.begin();
	  for(; k != mices.end(); k++) {
	    
	    if((*k) > aux)
	      break;
	  }
	  
	  mices.erase(--k);
	}
      }      
    }
    
    cout << m - mices.size() << '\n' ;
  }  
  return 0;
}
