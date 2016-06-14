#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int find(vi arr, int val) {

  for(int i=0; i<arr.size(); i++)
    if(arr[i] == val)
      return i;
  
  return -1;
}

void insert(vi &arr, int pos, int val){
  arr.insert(arr.begin() + pos, val);
}

void remove(vi &arr, int pos) {
  arr.erase(arr.begin() + pos);
}

int main() {
  int n, t, a, b, t2;
  char op;

  cin >> n;
  vi lis(n);
  
  for(int i=0; i<n; i++)
    cin >> lis[i];

  cin >> n;
  for(int i=0; i<n; i++) {

    cin >> op >> a;
    
    if(op == 'R') {
      
      t = find(lis, a);
      remove(lis, t);
      
    } else if(op == 'I'){
      
      cin >> b;
      t = find(lis, b);
      insert(lis, t + 1, a);

    } else {
      
      cin >> b;
      t = find(lis, a);
      t2 = find(lis, b);

      if(t == t2)
	cout << "-1\n";
      else
	cout << (max(t, t2) - min(t, t2) - 1) << '\n';
    }

  }

  return 0;
}
