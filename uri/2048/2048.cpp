#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, cont = 0;
  double t, t2;
  vector<int> votes;
  cin >> n;

  for(int i=0; i<n; i++) {
    cin >> t;
    cont += t;
    votes.push_back(t);
  }

  sort(votes.begin(), votes.end());

  t = (votes.back() * 100) / (double)cont;
  t2 = (votes[votes.size() - 2] * 100) / (double)cont;
  
  if(t >= 45.0)
    cout << "1\n";
  else if(t >= 40 && (t - t2) >= 10.0)
    cout << "1\n";
  else
    cout << "2\n";
  
  return 0;
}
