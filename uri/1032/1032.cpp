#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

int round(vector<int> arr, int ant, int i) {

  if(arr.size() == 1)
    return arr[0] + 1;

  ant = (ant + primes[i] - 1) % arr.size();
  arr.erase(arr.begin() + ant);

  return round(arr, ant, i + 1);
}

const int MAX = 100000;
bool sieve[MAX + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;

  memset(sieve, 1, MAX + 1);

  int root = sqrt(MAX);
  for(int i=2; i<=root; i++){
    
    if(sieve[i]) {
      for(int j=i*i; j<=MAX; j+=i)
	sieve[j] = 0;
    }    
  }

  for(int i=2; i<MAX; i++){
    if(sieve[i])
      primes.push_back(i);
  }

  while(cin >> n && n){
    vector<int> people(n);
    iota(people.begin(), people.end(), 0);
    cout << round(people, 0, 0) << '\n';
  }

}
