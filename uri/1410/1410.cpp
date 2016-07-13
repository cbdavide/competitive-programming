#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {

  int a, d;

  while(cin >> a >> d && (a + d)) {
    vi att(a), deff(d);

    for(int i=0; i<a; i++)
      cin >> att[i];

    for(int i=0; i<d; i++)
      cin >> deff[i];

    sort(att.begin(), att.end());
    sort(deff.begin(), deff.end());

    if(att[0] >= deff[1])
      cout << "N\n";
    else
      cout << "Y\n";
    
  }  
  return 0;
}
