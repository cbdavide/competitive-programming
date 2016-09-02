#include <bits/stdc++.h>
using namespace std;

int findAlliteration(string a) {
  int all = 0;
  char c;
  string word;
  bool cond = 0;

  stringstream ss(a);
  ss >> word;

  c = tolower(word[0]);
  
  while(ss >> word){
    if(c == tolower(word[0])) {

      if(!cond){
	all++;
	cond = true;
      }
      
    } else {
      cond = false;
      c = tolower(word[0]);
    }
  }

  return all;
}

int main() {
  string line;

  while(getline(cin, line))
    cout << findAlliteration(line) << '\n';
  
  return 0;
}
