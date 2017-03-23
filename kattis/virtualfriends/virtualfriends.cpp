#include <bits/stdc++.h>
using namespace std;

#define size 50001

typedef map<string, int> msi;

int *arr = new int [size];
int *peso = new int [size];

void init() {
    for(int i=0; i<size; i++) {
        arr[i] = i;
        peso[i] = 1;
    }
}

int find(int i) {
    if(arr[i] == i)
        return i;

    arr[i] = find(arr[i]);
    return arr[i];
}

void join(int i, int j) {
    int a = find(i);
    int b = find(j);

    if(a == b)
        return;

    if(peso[a] > peso[b]) {
        arr[b] = arr[a];
        peso[a] += peso[b];
    } else {
        arr[a] = arr[b];
        peso[b] += peso[a];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, cont;
    string a, b;
    cin >> t;
    while(t--) {
        msi mapita;
        cont = 0;
        init();

        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a >> b;

            if(mapita[a] == 0)
                mapita[a] = ++cont;

            if(mapita[b] == 0)
                mapita[b] = ++cont;

            join(mapita[a], mapita[b]);
            cout << peso[find(mapita[a])] << '\n';

        }
    }
    return 0;
}
