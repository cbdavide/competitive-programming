#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef vector<pis> vpis;

map<char, pii> key;

int distance(string &a, string &b) {
    int dis = 0;
    for(int i=0; i<a.size(); i++) {
        dis += abs(key[a[i]].first - key[b[i]].first);
        dis += abs(key[a[i]].second - key[b[i]].second);
    }

    return dis;
}

int main() {
    key['q'] = pii(0, 0); key['w'] = pii(0, 1);
    key['e'] = pii(0, 2); key['r'] = pii(0, 3);
    key['t'] = pii(0, 4); key['y'] = pii(0, 5);
    key['u'] = pii(0, 6); key['i'] = pii(0, 7);
    key['o'] = pii(0, 8); key['p'] = pii(0, 9);

    key['a'] = pii(1, 0); key['s'] = pii(1, 1);
    key['d'] = pii(1, 2); key['f'] = pii(1, 3);
    key['g'] = pii(1, 4); key['h'] = pii(1, 5);
    key['j'] = pii(1, 6); key['k'] = pii(1, 7);
    key['l'] = pii(1, 8);

    key['z'] = pii(2, 0); key['x'] = pii(2, 1);
    key['c'] = pii(2, 2); key['v'] = pii(2, 3);
    key['b'] = pii(2, 4); key['n'] = pii(2, 5);
    key['m'] = pii(2, 6);

    int n, m;
    string word, aux;

    cin >> n;
    while(n--) {
        cin >> word >> m;
        vpis result(m);

        for(int i=0; i<m; i++) {
            cin >> aux;
            result[i] = pis(distance(word, aux), aux);
        }

        sort(result.begin(), result.end());
        for(int i=0; i<result.size(); i++) {
            cout << result[i].second << ' '
                 << result[i].first << '\n';
        }
    }

    return 0;
}
