#include <iostream>
using namespace std;

main() {
    int n, temp, cont = 0;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> temp;

        if(temp < 0)
            cont++;
    }
    cout << cont << '\n';
}
