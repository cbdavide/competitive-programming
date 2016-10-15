#include <bits/stdc++.h>
using namespace std;

bool compare(char a, char b, char c, char d) {
  return abs(a - b) == abs(c - d);
}

bool is_funny(string a, string b) {

  for(int i=1; i<a.size(); i++) {
    if(!compare(a[i], a[i - 1], b[i], b[i - 1]))
      return false;
  }

  return true;
}

int main() {
  int t;
  string a, b;

  cin >> t;
  while(t--) {
    cin >> a;

    b = a;
    reverse(b.begin(), b.end());

    if(is_funny(a, b))
      cout << "Funny\n";
    else
      cout << "Not Funny\n";      
  }

  return 0;
}
