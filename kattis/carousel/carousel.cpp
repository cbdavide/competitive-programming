#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool jiji(pii a, pii b) {
  return ((double)a.second/a.first) < ((double)b.second / b.first);
}

pii pick_best(vpii arr) {
  int i = 0;
  pii temp = arr[i], next = arr[++i];

  double a = (double)temp.second / temp.first;
  double b = (double)next.second / next.first;

  while(a == b) {
    if(next.first > temp.first)
      temp = next;

    next = arr[++i];

    a = (double)temp.second / temp.first;
    b = (double)next.second / next.first;
  }

  return temp;
}

int main() {
  int n, m, a, b;

  while(cin >> n >> m && (n + m)) {
    vpii arr;

    for(int i=0; i<n; i++) {
      cin >> a >> b;

      if(a <= m)
        arr.push_back(pii(a, b));

    }

    sort(arr.begin(), arr.end(), jiji);

    if(arr.empty()) {
      cout << "No suitable tickets offered\n";
    } else {
      pii best = pick_best(arr);
      cout << "Buy " << best.first << " tickets for $"
           << best.second << '\n';
    }
  }

  return 0;
}
