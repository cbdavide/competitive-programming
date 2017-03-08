#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, vi> mapa;

int main() {
  int t, cod, pro, k = 0, maxi;

  while(cin >> t && t) {
    mapa mapita;
    maxi = 0;
    for(int i=0; i<t; i++) {
      cin >> cod >> pro;
      maxi = max(maxi, pro);
      mapita[pro].push_back(cod);
    }

    vi value = mapita[maxi];

    cout << "Turma " << ++k << '\n';
    for(int i=0; i<value.size(); i++)
        cout << value[i] << ' ';

    cout << "\n\n";
  }
  return 0;
}
