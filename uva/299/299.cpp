#include <bits/stdc++.h>
using namespace std;

int sort(int *arr, int size) {
    int cont = 0, aux;
    for(int i=0; i<size; i++) {
        for(int j=i; j<size; j++) {
            if(arr[j] < arr[i]) {
                cont++;
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
    return cont;
}

main() {
    int nCases, nc, *c;
    cin >> nCases;

    for(int i=0; i<nCases; i++) {
        cin >> nc;
        c = new int[nc];
        for(int j=0; j<nc; j++) {
            cin >> c[j];
        }
        //Print the swaps
        cout << "Optimal train swapping takes " <<
            sort(c, nc) << " swaps." << '\n';
    }
}
