#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int size) {
    int aux;
    for(int i=0; i<size; i++) {
        for(int j=i; j<size; j++) {
            if(arr[i] > arr[j]) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

int find(int *arr, int size, int value) {
    for(int i=0; i<size; i++) {
        if(arr[i] == value)
            return i;
    }
    return -1;
}

main() {
    int nmarbles, nquerys, query, index, k=1;
    int *marbles;
    while(cin >> nmarbles >> nquerys && nmarbles && nquerys) {
        marbles = new int[nmarbles];
        for(int i=0; i<nmarbles; i++) {
            cin >> marbles[i];
        }
        bubbleSort(marbles, nmarbles);//Array sorted.
        cout << "CASE# " << k++ << ":\n";
        for(int i=0; i<nquerys; i++) {
            cin >> query;
            index = find(marbles, nmarbles, query);
            if(index != -1) {
                cout << query << " found at " << index+1 << '\n';
            } else {
                cout << query << " not found" << '\n';
            }
        }
    }
}
