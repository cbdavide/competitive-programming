#include <bits/stdc++.h>
using namespace std;

bool check_invariant(vector<string> &arr, int c) {
    unordered_set<string> container(arr.begin(), arr.end());
    return container.size() == c;
}

void chop(vector<string> &arr, int c) {
    for(int i=0; i<c; i++)
        arr[i].erase(0, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    string temp;
    int cont = 0;

    cin >> r >> c;
    vector<string> cols(c);

    cin >> temp;
    for(int i=0; i<r - 1; i++) {
        cin >> temp;
        for(int j=0; j<c; j++) {
            cols[j].push_back(temp[j]);
        }
    }

    while(check_invariant(cols, c)) {
        cont++;
        chop(cols, c);
    }

    cout << cont << '\n';
}
