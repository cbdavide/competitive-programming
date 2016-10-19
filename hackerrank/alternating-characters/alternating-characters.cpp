#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cont;
  char ant;
  string s;

  cin >> n;
  while(n--) {
    cont = 0;
    cin >> s;

    ant = s[0];
    for(int i=1; i<s.size(); i++) {
      if(s[i] == ant)
        cont++;
      else
        ant = s[i];
    }

    cout << cont << '\n';
  }
  return 0;
}
