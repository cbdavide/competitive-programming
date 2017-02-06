#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<long long> pq;
int main() {
    long long m, n, t, cont;
    pq cola;
    cin >> m >> n;
    for(int i=0; i<m; i++) {
        cin >> t;
        cola.push(t);
    }

    cont = 0;
    for(int i=0; i<n; i++) {
        t = cola.top();
        cola.pop();

        cont += t;
        cola.push(--t);
    }

    cout << cont << '\n';
    return 0;
}
