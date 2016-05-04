#include <iostream>
#include <string>
using namespace std;

void add_padding(string& str, int n) {
    for(int i=0; i<n; i++)
        str.append(" ");
}

int find_next(int l, int u) {
    while(l % u != 0)
        l++;
    return l;
}

main() {
    int n, *l, times, k;
    string msg, answ;

    while(cin >> n && n != 0) {
        l = new int[n];

        for(int i=0; i<n; i++)
            cin >> l[i];

        getline(cin, msg);
        getline(cin, msg);

        if(msg.size() % n == 0){
            times = msg.size() / n;
        } else {
            k = find_next(msg.size(), n);
            times = k / n;
            add_padding(msg, k - msg.size());
        }

        k = 0;
        answ = "";
        for(int i=0; i<times; i++) {
            for(int j=0; j<n; j++, k++) {
                answ += msg[l[j] - 1 + n*i];
            }
        }

        cout << '\'' << answ << "'\n";
    }
}
