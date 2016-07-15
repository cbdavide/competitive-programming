#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int counter(vi arr, int l) {
  int cont = 0;
  sort(arr.begin(), arr.end());

  for(int i=arr.size() - 1; i>=0; i--){
    if(arr[i] < l)
      break;
    cont++;
  }
  return cont;
}

int main() {
  int q, r, a;
  while(cin >> q >> r && (q + r)) {
    vi questions(q, 0);

    for(int i=0; i<q; i++) {
      cin >> a;
      questions[a - 1]++;
    }
    cout << counter(questions, r) << '\n';
  }
  return 0;
}
