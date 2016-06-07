#include <iostream>
using namespace std;

int main() {
  int n, t, l[] = {0, 0, 0, 0};

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> t;

    if(t % 2 == 0)
      l[0]++;
    if(t % 3 == 0)
      l[1]++;
    if(t % 4 == 0)
      l[2]++;
    if(t % 5 == 0)
      l[3]++;
  }

  for(int i=0; i<4; i++)
    cout << l[i] << " Multiplo(s) de " << (i+2) << '\n';
  
  return 0;
}
