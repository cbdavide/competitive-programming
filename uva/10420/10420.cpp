#include <bits/stdc++.h>
using namespace std;

main() {
    int nlines, index;
    string country, name;
    map<string, int> data;
    cin >> nlines;
    getline(cin, country);

    for(int i=0; i<nlines; i++) {
        cin >> country;
        getline(cin, name);

        data[country]++;
    }
    map<string, int>::iterator i;
    for(i=data.begin(); i!=data.end(); i++) {
        cout << (*i).first << " " << (*i).second << '\n';
    }
}
