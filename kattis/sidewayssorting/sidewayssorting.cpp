#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vi;
typedef vector<vi> vii;

vi tolower(vi v) {
  for(int i=0; i<v.size(); i++)
    v[i] = tolower(v[i]);
  return v;
}

bool compare(vi a, vi b){
  return tolower(a) < tolower(b);
}

int main() {
  int r, c;
  char t;
  bool cond = false;

  while(cin >> r >> c && (r + c)){
    if(cond)
      cout << '\n';

    
    vii matrix(c);
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
	cin >> t;
	matrix[j].push_back(t);
      }
    }
    
    sort(matrix.begin(), matrix.end(), compare);

    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
	cout << matrix[j][i];
      }
      cout << '\n';
    }
    cond = true;
  }  
  return 0;
}
