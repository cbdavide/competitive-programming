#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
  int n, ant;

  while(cin >> n && n) {
    vi s(n);

    for(int i=0; i<n; i++)
      cin >> s[i];
    
    cin >> ant;

    while(s[ant - 1] != ant)
      ant = s[ant -1];

    cout << ant << '\n';
  }
  return 0;
}
