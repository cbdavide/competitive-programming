#include <bits/stdc++.h>
using namespace std;

int main() {

  int n, r = 0, s = 0;
  string s1, s2;

  cin >> n;
  cin >> s1 >> s2;

  for(int i=0; i<n; i++) {
    if(s1[i] == s2[i]) {
      r++;
      s1[i] = s2[i] = '_';
    }
  }

  for(int i=0; i<s2.size(); i++) {
    for(int j=0; j<s1.size(); j++){
      if(s2[i] != '_' && s2[i] == s1[j]) {
	s++;
	s2[i] = s1[j] = '_';
	break;
      }
    }
  }

  cout << r << ' ' << s << '\n';

  return 0;
}
