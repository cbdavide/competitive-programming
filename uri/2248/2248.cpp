#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool cond(pii a, pii b) {
  return a.first > b.first;
}

int main() {
  int t, cod, pro, k = 0;

  while(cin >> t && t) {
    vpii arr(t);

    for(int i=0; i<t; i++) {
      cin >> cod >> pro;
      arr[i] = pii(pro, cod);
    }

    sort(arr.begin(), arr.end(), cond);

    int i = 1;
    cout << "Turma " << ++k << '\n';
    cout << arr[0].second << " ";
    while(arr[0].first == arr[i].first && i < arr.size()) {
      cout << arr[i].second << " ";
      i++;
    }
    cout << "\n\n";
  }
  return 0;
}
