#include <bits/stdc++.h>
using namespace std;

int *arr, *T, *cp, best;

void backtrack(int capacity, int c, int n, int total) {
    if(capacity > total) return;
    if(c == n) {
        if(capacity > best) {
            best = capacity;
            for(int i=0; i<n; i++) cp[i] = arr[i];
        }

    } else {
        arr[c] = T[c];
        backtrack(capacity + T[c], c + 1, n, total);
        arr[c] = 0;
        backtrack(capacity, c + 1, n, total);
    }

}

int main() {
    int capacity, n;
    while (cin >> capacity) {
        cin >> n;
        T = new int[n];
        arr = new int[n];
        cp = new int[n];

        best = -1e9;
        memset(arr, 0, sizeof(int)*n);
        for(int i=0; i<n; i++) cin >> T[i];
        backtrack(0, 0, n, capacity);
        for(int i=0; i<n; i++) if(cp[i]) cout << cp[i] << ' ';
        cout << "sum: " << best << '\n';

    }
    return 0;
}
