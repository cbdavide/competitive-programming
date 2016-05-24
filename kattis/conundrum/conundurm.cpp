#include <bits/stdc++.h>
using namespace std;

int main() {

    char per[] = {'P', 'E', 'R'};
    string line;
    int cont = 0;

    cin >> line;
    for(int i=0; i<line.size(); i++) {
        if(line[i] != per[i % 3]){
            line[i] = per[i % 3];
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}
