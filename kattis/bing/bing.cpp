#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, cont;
    string *words, temp;

    while(cin >> n) {
        words = new string[n];

        for(int i=0; i<n; i++)
            cin >> words[i];

        for(int i=0; i<n; i++){
            cont = 0;

            for(int j=i-1; j>=0; j--) {

                if(words[i] == words[j].substr(0, words[i].size()))
                    cont++;
            }
            cout << cont << '\n';
        }
    }

    return 0;
}
