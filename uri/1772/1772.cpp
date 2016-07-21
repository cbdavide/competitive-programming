#include<bits/stdc++.h>
using namespace std;

typedef bitset<33> bi;
typedef vector<bi> vbi;

bi build(bi arr, int a, int b) {
  bi answ = arr;
  bool x = answ[a], y = answ[b];

  answ[a] = y;
  answ[b] = x;

  return answ;
}

bool compare(bi a, bi b) {
  return a.to_ulong() < b.to_ulong();
}

int main() {
  unsigned int n;
  int k, a, b;
  bi res, min, max;

  while(cin >> n >> k && (n + k)){
    vbi arr(k + 1);
    arr[0] = bi(n);

    for(int i=1; i<=k; i++){
      cin >> a >> b;
      arr[i] = build(arr[i - 1], a, b);
    }

    res = arr.back();

    sort(arr.begin(), arr.end(), compare);

    min = arr[0];
    max = arr.back();
    
    cout << res.to_ulong() << ' ' <<  max.to_ulong()
	 << ' ' << min.to_ulong() << '\n';

  }  
  return 0;
}
