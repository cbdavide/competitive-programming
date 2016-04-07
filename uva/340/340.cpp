#include <bits/stdc++.h>
using namespace std;

main() {

    int length, *code, *guess;
    int strong, weak, game=1;
    bool cond;

    while(cin >> length && length != 0) {
        code = new int[length];
        guess = new int[length];
        cond = true;

        for(int i=0; i<length; i++) {//Code input
            cin >> code[i];
        }
        cout << "Game " << game++ << ":" << '\n';
        while(cond) {
            strong = weak = 0;
            vector<int> missC(10, 0);
            vector<int> missG(10, 0);

            for(int i=0; i<length; i++) {//Guess code input
                cin >> guess[i];
            }

            if(guess[0] == 0) {
                cond = false;
            } else {

                for(int i=0; i<length; i++) {
                    if(code[i] == guess[i]) {
                        strong++;
                    } else {
                        missC[code[i]]++;
                        missG[guess[i]]++;
                    }
                }
                for(int i=0; i<10; i++) {
                    weak += min(missG[i], missC[i]);
                }

                cout << "    (" << strong << "," << weak << ")" << '\n';

            }
        }
    }
}
