#include <bits/stdc++.h>
using namespace std;

int main() {
    int diff, m, w, cont, a, b;
    char c, t1, t2;
    deque<char> q;
    cin >> diff;
    while(cin >> c) q.push_back(c);

    cont = m = w = 0;
    while(!q.empty()) {
        c = q.front();
        a = (c == 'M') ? m + 1 : m;
        b = (c == 'W') ? w + 1 : w;
        q.pop_front();
        if(abs(a - b) > diff ) {
            t1 = c;
            t2 = q.front(); q.pop_front();
            if(c == t2) break;
            else {
                q.push_front(c);
                q.push_front(t2);
            }
        }else {
            m = a; w = b;
            cont++;
        }
    }
    cout << cont << '\n';
    return 0;
}
