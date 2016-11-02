#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream cin("team.in");
ofstream cout("team.out");

int pos[6][3] = {{0, 1, 2}, {0, 2, 1},
                 {1, 0, 2}, {1, 2, 0},
                 {2, 0, 1}, {2, 1, 0}};

void read(int *arr){
  for (size_t i = 0; i < 3; i++)
    cin >> arr[i];
}

int main() {

  int a[3], b[3], c[3];
  double max = 0, temp, r;

  read(a);
  read(b);
  read(c);

  for(size_t i = 0; i < 6; i++) {
    temp = 0;
    temp += pow(a[pos[i][0]], 2);
    temp += pow(b[pos[i][1]], 2);
    temp += pow(c[pos[i][2]], 2);

    r = sqrt(temp);

    if(r > max)
      max = r;
  }

  cout << setprecision(16) << (double)max << endl;

  return 0;
}
