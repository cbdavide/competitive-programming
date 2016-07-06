#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool is_yes(vi arr, int n) {
  for(int i=0; i<arr.size(); i++){
    if(arr[i] == n)
      return true;
  }
  return false;
}

int main() {
  int n, d, t;

  while(cin >> n >> d && (n + d)){

    vi s(n, 0);
    
    for(int i=0; i<d; i++) {
      for(int j=0; j<n; j++) {
	cin >> t;
	s[j] += t;
      }
    }

    if(is_yes(s, d))
      cout << "yes\n";
    else
      cout << "no\n";    

  }
  return 0;
}
