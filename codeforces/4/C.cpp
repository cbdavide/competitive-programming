#include <bits/stdc++.h>
using namespace std;

typedef map<string, int> msi;

int main() {
    int n;
    string a;
    msi mapita;

    cin >> n;
    while(n--) {
        cin >> a;
        if(mapita[a] == 0) {
            mapita[a]++;
            cout << "OK\n";
        }else {
            cout << a << mapita[a] << '\n';
            mapita[a]++;
        }
    }
    return 0;
}
