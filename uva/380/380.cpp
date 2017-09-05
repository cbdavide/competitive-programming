#include <bits/stdc++.h>
using namespace std;

typedef vector< string* > vs3;
typedef map<string, vs3> msvs;
typedef map<string, bool> msb;

string add(string a, string b) {
    int n1 = stoi(a), n2 = stoi(b);
    string r = to_string(n1 + n2);
    while(r.size() < 4) r.insert(0, "0");
    return r;
}

string backtrack(msvs &T, msb &vis, string tim, string source) {
    if(vis[source]) return "9999";
    vis[source] = true;
    for(int i=0; i<T[source].size(); i++) {
        string to = add(T[source][i][0], T[source][i][1]);
        if(tim >= T[source][i][0] && tim <= to) 
            return backtrack(T, vis, tim, T[source][i][2]);
    }
    return source;
}

int main() {
    int t; cin >> t;
    cout << "CALL FORWARDING OUTPUT\n";
    for(int z=1; z<=t; z++) {
        cout << "SYSTEM " << z << '\n';
        msvs registry;
        while(true) {
            string source; cin >> source;
            if(source == "0000") break;
            string *arr = new string[3];
            cin >> arr[0] >> arr[1] >> arr[2];
            registry[source].push_back(arr);
        }
        while(true) {
            msb vis;
            string tim, to;
            cin >> tim;
            if(tim == "9000") break;
            cin >> to;
            cout << "AT " << tim << " CALL TO "
                 << to << " RINGS " << backtrack(registry, vis, tim, to)
                 << '\n';
        }
    }
    cout << "END OF OUTPUT\n";
    return 0;
}
