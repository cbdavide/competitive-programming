#include <iostream>
#include <vector>
using namespace std;

main() {
    int width, ndivs, *divs;
    bool *check;

    cin >> width >> ndivs;
    divs = new int[width];
    check = new bool[width+1];

    for(int i=0; i<ndivs; i++) {
        cin >> divs[i];
        check[divs[i]] = true;
        check[width - divs[i]] = true;
    }

    for(int i=0; i<ndivs; i++) {
        for(int j=i+1; j<ndivs; j++) {
            check[divs[j] - divs[i]] = true;
        }
    }
    check[width] = true;

    for(int i=0; i<width; i++) {
        if(check[i])
            cout << i << ' ';
    }
    cout << width << '\n';

}
