#include <bits/stdc++.h>
using namespace std;

typedef map<int, int> mii;
int main() {

  int n, t;
  mii ratio;
  
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> t;
    ratio[t]++;
  }

  mii::iterator i = ratio.begin();
  for( ; i != ratio.end(); i++)
    cout << (*i).first << " aparece " << (*i).second << " vez(es)\n";

  return 0;
}
