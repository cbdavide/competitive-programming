#include <bits/stdc++.h>
using namespace std;

int inverted_values[] = {0, 1, 2, 0, 0, 5, 9 , 0, 8, 6};
bool valid_values[] = {1, 1, 1, 0, 0, 1, 1, 0, 1, 1};
bool is_valid(int n) {
    string value = to_string(n);

    for(int i=0; i<value.size(); i++) {
        if(!valid_values[value[i] - 48])
            return false;
    }
    return true;
}

string invert(int n) {
    string value = to_string(n);
    reverse(value.begin(), value.end());

    for (int i = 0; i < value.size(); i++) {
        value[i] = inverted_values[value[i] - 48] + 48;
    }

    return value;
}

main() {
    int n, last_value;
    map<int, string> values;
    values[0] = "0";
    values[1] = "1";
    values[2] = "2";
    values[3] = "5";

    last_value = 5;

    while(cin >> n) {
        if(n >= values.size()) {
            for(int j=values.size(), i=last_value+1; j<=n; i++) {
                if(is_valid(i)) {
                    values[j] = invert(i);
                    j++;
                    last_value = i;
                }
            }
        }
        cout << values[n] << '\n';
    }
}
