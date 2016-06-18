#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int get_min(vi arr) {
  int min = arr[0];
  for(int i=1; i<arr.size(); i++){
    if(arr[i] < min)
      min = arr[i];
  }
  return min;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int q, c, k, aux, min;

  while(cin >> q >> c >> k && (q + c + k)){
    vi numbers(k, 0), ans;

    for(int i=0; i<q; i++){

      for(int j=0; j<c; j++) {
	cin >> aux;
	numbers[aux - 1]++;
      }

    }

    min = get_min(numbers);

    for(int i=0; i<numbers.size(); i++){
      if(numbers[i] == min)
	ans.push_back(i + 1);
    }

    for(int i=0; i<ans.size(); i++){
      cout << ans[i];

      if(i < ans.size() - 1)
	cout << ' ';
    }
    cout << '\n';
  }
  return 0;
}
