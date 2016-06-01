#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {

  map<string, vi> travels;
  int n, y;
  string c;

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> c >> y;
    travels[c].push_back(y);
  }

  map<string, vi>::iterator k = travels.begin();
  for( ; k != travels.end(); k++)
    sort((*k).second.begin(), (*k).second.end());

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> c >> y;
    cout << travels[c][y-1] << '\n';
  }

  return 0;
}

