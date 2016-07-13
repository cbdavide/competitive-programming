#include<bits/stdc++.h>
using namespace std;

int main() {
  int teams, matches, cont, t;
  string name;
  
  while(cin >> teams >> matches && teams) {
    cont = 0;

    for(int i=0; i<teams; i++){
      cin >> name >> t;
      cont += t;
    }

    cout << ((matches * 3) - cont) << '\n';
  }  
  return 0;
}
