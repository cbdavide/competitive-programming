#include <bits/stdc++.h>
using namespace std;

main() {
    int n, b1, e1, b2, e2, a;
    string l1, l2;
    string s1, s2, o1, o2;
    cin >> n;
    getline(cin, l1); // Salvando al soldado Ryan.
    for(int i=0; i<n; i++) {
        getline(cin, l1);
        getline(cin, l2);

        b1 = l1.find_first_of('<');
        e1 = l1.find_first_of('>');
        b2 = l1.find_last_of('<');
        e2 = l1.find_last_of('>');
        a = l2.find("...");

        s1 = l1.substr(b1+1, e1-b1-1);
        s2 = l1.substr(e1+1, b2-e1-1);

        o1 = l1.substr(b2+1, e2-b2-1);
        o2 = l1.substr(e2+1);

        l1.erase(b1, 1);
        l1.erase(e1-1, 1);
        l1.erase(b2-2, 1);
        l1.erase(e2-3, 1);

        l2.replace(a, 3, o1+s2+s1+o2);

        cout << l1 << endl;
        cout << l2 << endl;
    }
}
