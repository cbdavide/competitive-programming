#include <bits/stdc++.h>
using namespace std;

int main() {
    int root;
    long long n;
    map<int, int>::iterator j;

    while(cin >> n) {
        map<int, int> primal;

        if(n < 0) {
            n *= -1;
            cout << "-1 ";
        }

        while(n % 2 == 0) {
            primal[2]++;
            n /= 2;
        }

        root = sqrt(n);
        for(int i = 3; i <= root; i += 2) {
            while(n % i == 0) {
                primal[i]++;
                n /= i;
            }
        }

        if(n > 2)
            primal[n]++;

        j = primal.begin();
        for( ; j != primal.end(); j++) {
            if((*j).second == 1)
                cout << (*j).first;
            else
                cout << (*j).first << '^' << (*j).second;

            if(j != --primal.end())
                cout << ' ';
        }
        cout <<  '\n';
    }


}
