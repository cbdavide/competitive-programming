#include <bits/stdc++.h>
using namespace std;

char buffer[1000000001];//The only way to declare arrays this big
int main() {
    //Necessary when we are dealing with a lot of I/O
    //And you're troubeling with TLE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int jack, jill, temp, cont;

    while((cin >> jack >> jill ) && (jack != 0 || jill != 0 )) {
        cont = 0;
        memset(buffer, 0, sizeof(buffer));

        for(int i=0; i<jack+jill; i++) {
            cin >> temp;

            if(buffer[temp])
                cont++;
            else
                buffer[temp] = 1;

        }

        cout << cont << '\n';
    }
    return 0;
}
