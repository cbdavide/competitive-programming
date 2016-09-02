#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, size, cond = 0;
  string word;

  while(cin >> n && n){
    size = 0;
    vs list(n);

    for(int i=0; i<n; i++){
      cin >> list[i];

      if(list[i].size() > size)
	size = list[i].size();
    }

    if(cond)
      cout << '\n';
    else
      cond = 1;

    for(int i=0; i<n; i++)
      cout << right << setw(size) << list[i] << '\n';

  }
  return 0;
}
