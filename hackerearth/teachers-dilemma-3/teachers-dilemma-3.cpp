#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

void init(int *arr, int *size, int n) {
    for(int i=0; i<n; i++) {
        arr[i] = i;
        size[i] = 1;
    }
}

int find(int *arr, int i) {
    while(arr[i] != i) {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void join(int *arr, int *size, int i, int j) {
    int a = find(arr, i);
    int b = find(arr, j);

    if(a == b)
        return;

    if(size[a] < size[b]) {
        arr[a] = arr[b];
        size[b] += size[a];
    } else {
        arr[b] = arr[a];
        size[a] += size[b];
    }
}

int main() {
    long long r = 1;
    int n, m, a, b;

    cin >> n >> m;
    int *arr = new int[++n];
    int *size = new int[n];

    init(arr, size, n);

    for(int i=0; i<m; i++){
        cin >> a >> b;
        join(arr, size, a, b);
    }

    for(int i=1; i<n; i++) {
        if(arr[i] == i)
            r = ((r % MOD) * (size[i] % MOD)) % MOD;
    }

    cout << r << '\n';
    return 0;
}
