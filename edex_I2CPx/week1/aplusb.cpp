#include <fstream>
using namespace std;

int main() {
  ifstream cin("aplusb.in");
  ofstream cout("aplusb.out");

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
  return 0;
}
