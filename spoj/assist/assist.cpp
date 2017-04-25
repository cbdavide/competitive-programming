#include <bits/stdc++.h>
using namespace std;

#define MAX  34000
#define SIZE  3000

vector<bool> sieve(MAX, 1);
int lucky[SIZE];

int main() {
    int t;
    for(int i=1, k = 2; i<=SIZE; i++, k++) {
        while(!sieve[k]) k++;
        lucky[i] = k;

        for (int j=k+1, cont=0; j<=MAX; j++) {
            if(!sieve[j]) continue;
            cont++;
            if(cont == k) {
                sieve[j] = 0;
                cont = 0;
            }
        }
    }
    while(scanf("%d\n", &t) == 1 && t) {
        printf("%d\n", lucky[t]);
    }
    return 0;
}
