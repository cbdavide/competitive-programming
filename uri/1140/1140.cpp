#include <bits/stdc++.h>
using namespace std;

int main() {
  string line, word;
  char f;
  bool cond;

  while(getline(cin, line) && line != "*"){

    cond = true;
    stringstream ss(line);

    ss >> word;
    f = tolower(word[0]);

    while(ss >> word) {
      if(tolower(word[0]) != f){
	cond = false;
	break;
      }      
    }

    f = cond ? 'Y' : 'N';
    
    cout << f  << '\n';
  }
  return 0;
}
