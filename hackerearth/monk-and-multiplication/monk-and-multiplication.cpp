#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<long long> pq;

int main() {
    long long n, t, p, a, b, c;
    pq cola;

    cin >> n;
    cin >> t >> p;

    cola.push(t);
    cola.push(p);
    cout << -1 << '\n' << -1 << '\n';

    for(int i=2; i<n; i++) {
        cin >> t;
        cola.push(t);

        a = cola.top(); cola.pop();
        b = cola.top(); cola.pop();
        c = cola.top();

        cout << a * b * c << '\n';

        cola.push(a);
        cola.push(b);
    }

    return 0;
}
