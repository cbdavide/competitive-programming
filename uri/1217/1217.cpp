#include<bits/stdc++.h>
using namespace std;

double getDouble() {
  double foo;
  string n;
  cin >> foo;
  getline(cin, n);
  return foo;
}

int main() {
  int n, p;
  double price, totalS = 0, totalK = 0;
  string line, name;

  cin >> n;

  for(int i=0; i<n; i++){
    p = 0;
    totalS += getDouble();
    
    getline(cin, line);
    stringstream ss(line);

    while(ss >> name)
      p++;

    totalK += p;

    printf("day %d: %d kg\n", (i + 1), p);
        
  }

  totalK = totalK / n;
  totalS = totalS / n;
  
  printf("%.2f kg by day\n", totalK);
  printf("R$ %.2f by day\n", totalS);
  
  return 0;
}
