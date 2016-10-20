#include <bits/stdc++.h>
using namespace std;

void spiral(string **matrix, int fi, int fti, int si, int sti, int n, int p, string *arr) {

  if(n >= p)
    return ;

  for(int i=fi; i<=fti; i++)//Left
    matrix[i][fi - 1] = arr[n++];

  for(int j=fi; j<=fti; j++)//Bottom
    matrix[si + 1][j] = arr[n++];

  for(int i=si; i>=sti; i--)
    matrix[i][si + 1] = arr[n++];

  for(int j=si; j>=sti; j--)
    matrix[fi - 1][j] = arr[n++];

  spiral(matrix, fi - 1, fti + 1, si + 1, sti - 1, n, p, arr);

}

void print(string **matrix, int size, int padding) {
  for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++)
      cout << setw(padding) << matrix[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
  int size, start, reach, catched, l, h;

  while(cin >> size >> start) {
    l = sqrt(size);
    h = ceil(l / 2);

    string **matrix = new string*[l];
    string *n = new string[size];

    reach = start * 2;
    catched = reach + (reach / 2);

    if(catched <= size) {

      for(int i=0; i<size; i++)
        n[i] = to_string(i + 1);

      n[reach - 1] = "*";
      n[catched - 1] = "!";

      for(int i=0; i<l; i++)
        matrix[i] = new string[l];

      matrix[h][h] = "1";
      spiral(matrix, h, h + 1, h, h - 1, 1, size, n);

      print(matrix, l, matrix[0][0].size());

    } else {
      cout << "Raios! Raios Duplos! Raios Triplos!\n";
    }
  }
  return 0;
}
