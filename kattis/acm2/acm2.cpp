#include <bits/stdc++.h>
using namespace std;

int main() {
  int n_problems, index, ac, cont, penalty;
  ac = cont = penalty = 0;

  cin >> n_problems >> index;
  vector<int> times(n_problems);

  for(int i=0; i<n_problems; i++) {
      cin >> times[i];
  }

  if(times[index] <= 300) {
    ac++;
    cont += times[index];
    penalty += cont;

    times.erase(times.begin() + index);
    sort(times.begin(), times.end());

    int i = 0;
    while(true) {
      cont += times[i];

      if(cont > 300 || i == times.size())
        break;

      ac++;
      penalty += cont;
      i++;
    }

  }
  cout << ac << ' ' << penalty << '\n';
  return 0;
}
