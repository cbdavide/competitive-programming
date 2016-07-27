#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> pis;
typedef vector<pis> vpis;

int last(vpis arr) {
  int answ = 0;
  for(int i=1; i<arr.size(); i++){
    if(arr[i].first != arr[answ].first)
      break;
    else
      answ = i;
  }
  return answ;
}

int main() {
  int n, grade, k = 0;
  string name;

  while(cin >> n) {
    vpis arr;

    for(int i=0; i<n; i++) {
      cin >> name >> grade;
      arr.push_back(pis(grade, name));
    }

    sort(arr.begin(), arr.end());
    
    cout << "Instancia " << ++k << '\n'
	 << arr[last(arr)].second << "\n\n";
    
  }
  return 0;
}
