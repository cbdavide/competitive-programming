#include <bits/stdc++.h>
using namespace std;

typedef map<char, int> mci;
typedef map<char, bool> mcb;

int main() {
    int k, sum = 0;
    string n;
    cin >> k >> n;
    for(int i=0; i<n.size(); i++)
        sum += (n[i] - '0');
    sort(n.begin(), n.end());
    int cont = 0, i = 0;
    while(sum < k && i < n.size()) {
        if(n[i] == '9') {i++; continue;}
        sum += (9 - (n[i] - '0'));
        cont++; i++;
    }
    cout << cont << '\n';
    return 0;
}
