#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef set<pii> spii;

int main() {
  int n, a;

  while(cin >> n && n){
    spii arr;
    for(int i=0; i<n; i++){
      cin >> a;
      arr.insert(pii(a, i));
    }

    spii::iterator p = arr.end();
    --p;
    cout << (*--p).second + 1 << '\n';
  }  
  return 0;
}
