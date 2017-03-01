#include <bits/stdc++.h>
using namespace std;

float suma(float mat[12][12]) {
    float answ = 0;

    for(int i = 1; i<12; i++) {
        for(int j=0; j<i; j++) {
            answ += mat[i][j];
        }
    }

    return answ;
}

float promedio(float mat[12][12]) {
    double answ = 0;

    for(int i = 1; i<12; i++) {
        for(int j=0; j<i; j++) {
            answ += mat[i][j];
        }
    }

    return answ / 66;
}

int main() {
    float mat[12][12];
    char s;

    cin >> s;
    for(int i=0; i<12; i++) {
        for(int j=0; j<12; j++) {
            cin >> mat[i][j];
        }
    }

    if(s == 'S')
        printf("%.1f\n",suma(mat));
    else
        printf("%.1f\n",promedio(mat));

    return 0;
}
