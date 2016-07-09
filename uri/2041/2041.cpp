#include <bits/stdc++.h>
using namespace std;

string godelito(string s, int b, int e) {
  char mi;
  int h;
  string s1, s2, answ;

  if(b == e){
    answ = "1";
    answ.push_back(s[b]);
    return answ;
  }
  
  h = (b + e)/2;

  s1 = godelito(s, b, h);
  s2 = godelito(s, h + 1, e);

  if(s1.back() == s2[1]){
    mi = ((s1[s1.size() - 2] - 48) + (s2[0] - 48)) + 48;
    answ = s1.substr(0, s1.size() - 2);
    answ.push_back(mi);
    answ.push_back(s2[1]);
    return answ + s2.substr(2);
    
  } else
    return s1 + s2;
}
  
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  vector<string> words;
  words.push_back("3");
    
  while(cin >> n){

    if(n > words.size()){
      for(int i=words.size() - 1; i<n; i++)
	words.push_back(godelito(words[i], 0, words[i].size() - 1));
    }
    
    cout << words[n - 1] << '\n';
  }  
  return 0;
}
