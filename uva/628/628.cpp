#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

void backtrack(string cad, vs &arr, vs &words, int idx) {
    if(idx == cad.size()) {
        for(int i=0; i<arr.size(); i++)
            cout << arr[i];
        cout << '\n';
    } else if(cad[idx] == '0') {
        for(int i=0; i<10; i++) {
            arr[idx] = to_string(i);
            backtrack(cad, arr, words, idx + 1);
        }
    } else {
        for(int i=0; i<words.size(); i++) {
            arr[idx] = words[i];
            backtrack(cad, arr, words, idx + 1);
        }
    }
}

int main() {
    int n, q;
    string temp;
    while(cin >> n) {
        cout << "--\n";
        vs words(n);
        for(int i=0; i<n; i++) cin >> words[i];
        cin >> q;
        for(int i=0; i<q; i++) {
            cin >> temp;
            vs arr(temp.size());
            backtrack(temp, arr, words, 0);
        }
    }
    return 0;
}
