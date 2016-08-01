#include <iostream>
using namespace std;

int main() {
  int n, f;
  string name;

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> name >> f;
    
    if(name == "Thor")
      cout << "Y\n";
    else
      cout << "N\n";
  }  
  return 0;
}
