#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int findi(string line, char c, int from) {
    for(int i=from; i<line.size(); i++) {
        if(line[i] == c) return i;
    }
    return -1;
}

void build(string line, vi &deg, char p, int b, int e) {
    int i = b + 1;
    int j = findi(line, line[i], i + 1);
    deg[p - 'A']++;
    while(i<e) {
        deg[p - 'A']++;
        build(line, deg, line[i], i, j);
        i = j + 1;
        j = findi(line, line[i], i + 1);
    }
}

int main() {
    int t;
    string line;

    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> line;
        vi degree(26, 0);
        build(line, degree, line[0], 0, line.size() - 1);
        degree[line[0] - 'A']--;
        cout << "Case " << i << '\n';
        for(int j=0; j<degree.size(); j++) {
            if(degree[j] > 0)
                cout << (char)(j + 'A') << " = " << degree[j] << '\n';
        }
    }
    return 0;
}
