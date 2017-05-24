#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;
typedef priority_queue<ii, vii, greater<ii> > qii;

int main() {
    int num, t, k;
    string word;
    qii q; mii dic, cont;

    while(cin >> word && word != "#") {
        cin >> num >> t;
        dic[num] = t; cont[num] = 1;
        q.push({t, num});
    }
    cin >> k;
    for(int i=0; i<k; i++) {
        ii a = q.top(); q.pop();
        cout << a.S << '\n';
        cont[a.S]++;
        q.push({dic[a.S] * cont[a.S], a.S});
    }
    return 0;

}
