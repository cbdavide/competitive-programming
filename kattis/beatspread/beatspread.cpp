#include <iostream>
#include <cmath>
using namespace std;

bool is_int(float k) {
    return floor(k) == k;
}

int main() {
    int n, s, d;
    float x, y;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> s >> d;

        y = (s - d) / 2.0;
        x = y + d;

        if(is_int(x) && is_int(y) && y >= 0 && x >= 0)
            cout << (int)max(x,y) << " " << (int)min(x,y) << '\n';
        else
            cout << "impossible\n";

    }
    return 0;
}
