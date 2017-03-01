#include <bits/stdc++.h>
using namespace std;

string newline(string word, int d) {
    string line = "";
    for(int i=0; i<word.size(); i++) {
        for(int j=0; j<d; j++)
            line += word[i];
    }
    return line;
}

int main() {
    int n, m, a, b;
    string line;

    while(cin >> n >> m && (n + m)) {
        vector<string> mat(n);

        for(int i=0; i<n; i++)
            cin >> mat[i];

        cin >> a >> b;

        for(int i=0; i<n; i++) {
            line = newline(mat[i], b / m);
            for(int j=0; j<a / n; j++)
                cout << line << '\n';
        }
        cout << '\n';
    }
}
