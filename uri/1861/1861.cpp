#include <bits/stdc++.h>
using namespace std;

typedef map<string, int> msi;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  msi m, k;
  string murderer, killed;

  while(cin >> murderer >> killed) {
    m[murderer]++;
    k[killed]++;
  }

  cout << "HALL OF MURDERERS\n";
  
  msi::iterator i = m.begin();
  for( ; i != m.end(); i++){
    if(!k[(*i).first])
      cout << (*i).first << ' ' << (*i).second << '\n';
  }  
  return 0;
}
