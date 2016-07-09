#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {

  int n, m, root, ma, mi, o;
  vi primes;

  cin >> n >> m;

  ma = max(n, m);
  mi = min(n, m);

  bool sieve[ma + 1];
  memset(sieve, 1, ma + 1);

  root = sqrt(ma);
  for(int i=2; i<=root; i++){
    if(sieve[i]){
      for(int j=i*i; j<=ma; j+=i)
	sieve[j] = 0;
    }
  }

  for(int i=2; i<=ma; i++){
    if(sieve[i])
      primes.push_back(i);
  }

  for(o = 0; primes[o] <= mi && o < primes.size(); o++){}

  cout << primes[o - 1] * primes.back() << '\n';

  return 0;
}
