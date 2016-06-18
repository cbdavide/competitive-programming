#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int suicide_squad(vi &arr, int ant, int step) {

  if(arr.size() == 1)
    return arr[0];

  ant = (ant + step - 1) % arr.size();
  arr.erase(arr.begin() + ant);

  return suicide_squad(arr, ant, step);

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, p, s;

  cin >> n;
  for(int i=0; i<n; i++){

    cin >> p >> s;
    vi people(p);

    for(int j=0; j<p; j++)
      people[j] = j + 1;

    cout << "Case " << (i + 1) << ": "
	 << suicide_squad(people, 0, s) << '\n';
  }
  return 0;
}
