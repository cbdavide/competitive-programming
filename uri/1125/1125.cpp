#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> table){
  int max = table[0];
  for(int i=1; i<table.size(); i++){
    if(table[i] > max)
      max = table[i];
  }
  return max;
}

typedef vector<int> vi;
int main() {

  int pitz, players, t, rank, aux, max;

  while(cin >> pitz >> players && pitz + players) {

    vector<vi> races(pitz);
    //Reading races
    for(int i=0; i<pitz; i++){
      for(int j=0; j<players; j++){
	cin >> aux;
	races[i].push_back(aux);
      }
    }
    //Reading the puntiations
    cin >> t;
    for(int i=0; i<t; i++) {
      
      vi table(players + 1, 0);
      vi scores(players, 0);
      cin >> rank;
      
      for(int j=0; j<rank; j++)
	cin >> scores[j];

      for(int k=0; k<pitz; k++) {
	for(int l=0; l<players; l++){
	  table[l + 1] += scores[races[k][l] - 1];
	}
      }
      //Print winners;
      max = find_max(table);
      vi results;
      for(int h=1; h<table.size(); h++){
	if(table[h] == max)
	  results.push_back(h);
      }

      for(int h=0; h<results.size(); h++) {
	cout << results[h];

	if(h < results.size() - 1)
	  cout << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
