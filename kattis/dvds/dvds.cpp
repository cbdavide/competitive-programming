#include <bits/stdc++.h>
using namespace std;

bool is_unordered(int *arr, int i, int size){
  for(int j=i+1; j<size; j++){
    if(arr[i] > arr[j])
      return true;
  }
  return false;
}

int find_min(int *arr, int size) {
  int i = -1, val = 20000000;
  for(int j=0; j<size-1; j++){
    if(is_unordered(arr, j, size) && arr[j] < val){
      i = j;
      val = arr[i];
    }
  }

  return i;
}

void swape(int *arr, int i, int n){
  int aux = arr[i];
  for(int k=i+1; k<n; k++)
    arr[k-1] = arr[k];

  arr[n-1] = aux;
}

int main() {

  int n, t, *dvd, mi, cont;
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> t;
    cont = 0;
    dvd = new int[t];

    for(int j=0; j<t; j++)
      cin >> dvd[j];

    mi = find_min(dvd, t);
    while( mi != -1) {
      swape(dvd, mi, t);
      cont++;
      mi = find_min(dvd, t);
    }

    cout << cont << '\n';
  }
  return 0;
}
