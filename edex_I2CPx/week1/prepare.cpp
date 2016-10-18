#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

typedef vector<int> vi;

int reduce(vi arr1, vi arr2) {
  int answ = 0;
  for(int i=0; i<arr1.size(); i++)
    answ += max(arr1[i], arr2[i]);

  return answ;
}

int mini(vi arr1, vi arr2) {
  int m = 0;

  for(int i=1; i<arr1.size(); i++){
    if(abs(arr1[m] - arr2[m]) > abs(arr1[i] - arr2[i]))
      m = i;
  }

  return m;
}

int main() {
  ifstream cin("prepare.in");
  ofstream cout("prepare.out");

  int n, sum = 0;
  bool a = false, b = false;

  cin >> n;
  vi t(n), p(n);

  for(int i=0; i<n; i++)
    cin >> t[i];

  for(int i=0; i<n; i++)
    cin >> p[i];

  for(int i=0; i<n; i++) {
    if(t[i] > p[i])
      a = true;
    else if(p[i] > t[i])
      b = true;
  }

  if(!a && b)//Include a t
    p[mini(p, t)] = -1;

  if(!b && a) //Include a p
    t[mini(p, t)] = -1;

  sum = reduce(p, t);
  cout << sum << '\n';
  return 0;
}
