#include <bits/stdc++.h>
using namespace std;

int main() {

  int oset[] = {1, 1, 2, 2, 2, 8};
  int piece[6];

  for(int i=0; i<6; i++)
    cin >> piece[i];

  for(int i=0; i<6; i++){
    if(oset[i] == piece[i])
      cout << "0";
    else if(oset[i] > piece[i])
      cout << oset[i] - piece[i];
    else
      cout << (piece[i] - oset[i]) * -1;

    if(i < 5)
      cout << ' ';
  }

  cout << '\n';

  return 0;
  
}
