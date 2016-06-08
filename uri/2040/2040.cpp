#include <bits/stdc++.h>
using namespace std;

map<string, int>::iterator find_max(map<string, int> mapa) {
  map<string, int>::iterator i, m = mapa.begin();

  for(i = ++mapa.begin(); i != mapa.end(); i++) {
    if((*i).second > (*m).second)
      m = i;
  }  
  return m;
}

int main(){
  char c;
  int n, p, p1;
  string t, t1;
  map<string, int> table;

  while(cin >> n && n){
    for(int i=0; i<n; i++){
      cin >> t >> p;
      table[t] = p;
    }
    for(int i=1; i<=n/2; i++){
      cin >> t >> p >> c >> p1 >> t1;
      table[t] += p * 3;
      table[t1] += p1 * 3;

      if(p == p1) {
	table[t]++;
	table[t1]++;
      } else if(p > p1)
	table[t] += 5;
      else
	table[t1] += 5;      
    }
    
    map<string, int>::iterator max = find_max(table);
    if((*max).first == "Sport"){
      cout << "O Sport foi o campeao com "
	   << (*max).second << " pontos :D\n\n";
    } else {
      cout << "O Sport nao foi o campeao. O time campeao foi o "
	   << (*max).first  << " com "
	   << (*max).second << " pontos :(\n\n";
    }
    table.clear();
  }
  return 0;
}
