#include <bits/stdc++.h>
using namespace std;

bool is_all(bool *balls, int size) {
  for(int i=0; i<=size; i++){
    if(!balls[i])
      return false;
  }
  return true;
}

int main() {
  int n, b;

  while(cin >> n >> b && (n + b)){
    bool balls[n + 1];
    int remaind[b];
    memset(balls, 0, n + 1);
    balls[0] = true;

    for(int i=0; i<b; i++)
      cin >> remaind[i];

    for(int i=0; i<b; i++){
      for(int j=i+1; j<b; j++){
	balls[abs(remaind[i] - remaind[j])] = 1;
      }
    }

    if(is_all(balls, n))
      cout << "Y\n";
    else
      cout << "N\n";    
  }
  return 0;
}
