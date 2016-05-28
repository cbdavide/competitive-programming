#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << setprecision(15);

    double w, l, u, o;
    vector<int> cont(4);
    string s;

    cin >> s;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '_')
            cont[0]++;
        else if(islower(s[i]))
            cont[1]++;
        else if(isupper(s[i]))
            cont[2]++;
        else
            cont[3]++;
    }

    cout << (double)cont[0] / s.size() << '\n';
    cout << (double)cont[1] / s.size() << '\n';
    cout << (double)cont[2] / s.size() << '\n';
    cout << (double)cont[3] / s.size() << '\n';
    
    return 0;
}
