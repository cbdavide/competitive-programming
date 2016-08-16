#include <bits/stdc++.h>
using namespace std;

typedef bitset<64> bi;

string add(string a, string b) {
  string answ = "";

  for(int i=0; i<a.size() && i<b.size(); i++) {

    if(a[i] == b[i])
      answ += "0";
     else 
       answ += "1";
  }
  
  return answ;
}

int main() {
  unsigned int a, b;
  string answ;

  while(cin >> a >> b){
    bi n1(a), n2(b);
    answ = add(n1.to_string(), n2.to_string());

    bi result(answ);
    
    cout << result.to_ullong() << '\n';
  }  
  return 0;
}
