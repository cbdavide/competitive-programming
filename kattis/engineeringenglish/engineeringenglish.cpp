#include <bits/stdc++.h>
using namespace std;

string tolow(string word) {
  for(int i=0; i<word.size(); i++)
    word[i] = tolower(word[i]);

  return word;
}

int main() {

  string line, word, copy;
  map<string, int>dic;
  
  while(getline(cin, line)){
    vector<string> answ;
    stringstream ss(line);
    
    while(ss >> word) {
      copy = tolow(word);
    
      if(!dic[copy]){
        answ.push_back(word);
        dic[copy]++;
      } else {
        answ.push_back(".");
      }

    }

    for(int i=0; i<answ.size(); i++) {
      cout << answ[i];

      if(i < answ.size() - 1)
        cout << " ";
    }

    cout << '\n';
  }
  
  return 0;
}
