#include <iostream>
using namespace std;

int main() {
    int x, i;
    while(cin >> x && x) {
        i = 0;
        for(int j=1; i + j <= x; j++) {
            i += j;
        }
        cout << i << ' ' << x - i << '\n';
    }
    return 0;
}
