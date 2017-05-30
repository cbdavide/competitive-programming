#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef priority_queue<int, vi, greater<int> > pq;

int main() {
    int n, a, b,cont, total;
    while(cin >> n && n) {
        pq q;
        for(int i=0; i<n; i++) {
            cin >> a;
            q.push(a);
        }

        cont = total = 0;

        while(q.size() > 1) {
            a = q.top(); q.pop();
            b = q.top(); q.pop();

            cont = a + b;
            q.push(cont);
            total += cont;
        }
        cout << total << '\n';
    }
    return 0;
}
