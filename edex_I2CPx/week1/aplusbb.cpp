#include <fstream>
using namespace std;

int main() {
  ifstream cin("aplusbb.in");
  ofstream cout("aplusbb.out");

  long long a, b, c;
  cin >> a >> b;

  c = a + (b * b);
  cout << c << '\n';
  return 0;
}
