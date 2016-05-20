#include <bits/stdc++.h>
using namespace std;

int main() {

    int p, t, a, s, amount = 0, k = 0;
    vector<pair<int, int> > people;
    multiset<int> bigger;

    cin >> p >> t;
    for(int i=0; i<p; i++) {
        cin >> a >> s;
        people.push_back(pair<int, int>(s, a));
    }

    sort(people.begin(), people.end());
    reverse(people.begin(), people.end());

    for(int i = t-1; i >= 0; i--) {

        while(k < p && people[k].first == i) {
            bigger.insert(-people[k].second);
            k++;
        }

        if(!bigger.empty()) {
            amount += -*bigger.begin();
            bigger.erase(bigger.begin());
        }

    }

    cout << amount << '\n';
    return 0;
}
