#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int maxi(vi arr) {
  sort(arr.begin(), arr.end());
  return arr.back();
}

int max_max(vi arr) {
  int max = maxi(arr);

  for(int i=arr.size()-1; i>=0; i--){
    if(arr[i] == max)
      return i;
  }
}

int main() {
  string cad;

  while(cin >> cad) {
    vi digits(10, 0);

    for(int i=0; i<cad.size(); i++)
      digits[cad[i] - 48]++;

    cout << max_max(digits) << '\n';
  }  
  return 0;
}
