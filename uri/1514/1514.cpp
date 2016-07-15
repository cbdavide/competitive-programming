#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool typeOne(vi arr) {
  for(int i=0; i<arr.size(); i++) {
    if(arr[i] < 1)
      return false;
  }
  return true;
}

bool typeTwo(vi arr, int limit) {
  for(int i=0; i<arr.size(); i++){
    if(arr[i] >= limit)
      return false;
  }
  return true;
}

int main() {
  int n, m, a, cont;

  while(cin >> n >> m && (n + m)) {
    cont = 0;
    vi players(n, 0), problems(m, 0);

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
	cin >> a;
	players[i] += a;
	problems[j] += a;
      }
    }

    if(typeOne(players))
      cont++;
    if(typeTwo(players, m))
      cont++;
    if(typeOne(problems))
      cont++;
    if(typeTwo(problems, n))
      cont++;

    cout << cont << '\n';    
  }  
  return 0;
}
