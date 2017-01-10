#include <bits/stdc++.h>
using namespace std;

bool check_invariant(vector<string> arr) {
    set<string> container(arr.begin(), arr.end());
    return container.size() == arr.size();
}

void chop(vector<string> &arr) {
    for(int i=0; i<arr.size(); i++)
        arr[i].erase(0, 1);
}

void print(vector<string> arr) {
    int row = arr[0].size();
    for(int i=0; i<row; i++) {
        for(int j=0; j<arr.size(); j++) {
            cout << arr[j][i];
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    string temp;
    int cont = 0;

    cin >> r >> c;
    vector<string> cols(c);

    for(int i=0; i<r; i++) {
        cin >> temp;
        for(int j=0; j<c; j++) {
            cols[j].push_back(temp[j]);
        }
    }

    chop(cols);
    while(check_invariant(cols)) {
        cont++;
        chop(cols);
    }

    cout << cont << '\n';
}
