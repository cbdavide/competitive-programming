#include <bits/stdc++.h>
using namespace std;

bool isDifferent(string o, string s) {
  int cont = 0;
  
  if(o == s)
    return false;

  for(int i=0; i<o.size() && i<s.size(); i++) {
    if(o[i] != s[i])
      cont++;

    if(cont > 1)
      return true;    
  }

  return false;  
}

int main() {
  int n, m, cont;
  string name, sign;

  while(cin >> n && n) {
    cont = 0;
    map<string, string> list;

    for(int i=0; i<n; i++) {
      cin >> name >> sign;
      list[name] = sign;
    }

    cin >> m;
    for(int i=0; i<m; i++){
      cin >> name >> sign;
      if(isDifferent(list[name], sign))
	cont++;
    }
    cout << cont << '\n';
  }
  return 0;
}
