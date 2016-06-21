#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, s, t;

  cin >> n;
  
  for(int i=0; i<n; i++){
    set<int> sheeps;
    cin >> s;

    for(int j=0; j<s; j++){
      cin >> t;
      sheeps.insert(t);
    }

    cout << sheeps.size() << '\n';
  }
  return 0;
}
