#include <bits/stdc++.h>
using namespace std;

bool isPrefix(string s1, string s2) {
    for(int i=0; i<s1.size(); i++) {
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

main() {
    string line, answ;
    vector<string> set;
    int k = 1;
    while(cin >> line) {

        if(line != "9") {
            set.push_back(line);
        } else {
            answ = ""; //Reset the variable that works like a bool Important!
            sort(set.begin(), set.end());

            for(int i=0; i<set.size() && answ == ""; i++){
                for(int j=i+1; j<set.size() && answ == ""; j++) {
                    if(isPrefix(set[i], set[j])) {
                        answ = "not ";
                    }
                }
            }

            set.clear();
            cout << "Set " << k++ << " is "
                 << answ << "immediately decodable" << '\n';
        }
    }
}
