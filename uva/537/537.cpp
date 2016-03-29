#include <bits/stdc++.h>
using namespace std;

int findLin(string word, int since) {
    for(int i=since; i<word.size(); i++) {
        if(word[i] > '9')
            return i  - since;
    }
    return -1;
}

main() {
    map <char, float> prefix;
    prefix['m'] = 0.001;
    prefix['k'] = 1000;
    prefix['M'] = 1000000;

    int nCases;
    string line;
    int d1, d2, nDigits1, nDigits2;
    float f1, f2, pre1, pre2;
    char l1, l2, pr1, pr2;
    cin >> nCases;
    getline(cin, line);
    cout << setprecision(2);
    cout << fixed;

    for(int i=0; i<nCases; i++) {
        getline(cin, line);
        d1 = line.find_first_of('=');
        d2 = line.find_last_of('=');

        l1 = line[d1 - 1];
        l2 = line[d2 - 1];

        nDigits1 = findLin(line, d1+1);
        nDigits2 = findLin(line, d2+1);

        pr1 = line[d1 + nDigits1 + 1];//Prefix n° 1
        pre1 = prefix[pr1] == 0 ? 1 : prefix[pr1];

        pr2 = line[d2 + nDigits2 + 1];//Prefix n° 2
        pre2 = prefix[pr2] == 0 ? 1 : prefix[pr2];

        stringstream ss(line.substr(d1+1, nDigits1));
        ss >> f1;

        stringstream tt(line.substr(d2+1, nDigits2));
        tt >> f2;

        cout << "Problem #" << i+1 << '\n';
        if(l1 == 'U' && l2 == 'I' || l2 == 'U' && l1 == 'I') {
            cout << "P=" << (f1*pre1)*(f2*pre2) << "W" << '\n';
        } else if(l1 == 'P' && l2 == 'U') {
            cout << "I=" << (f1*pre1)/(f2*pre2) << "A" << '\n';
        } else if(l2 == 'P' && l1 == 'U') {
            cout << "I=" << (f2*pre2)/(f1*pre1) << "A" << '\n';
        } else if(l1 == 'P' && l2 == 'I' ){
            cout << "U=" << (f1*pre1)/(f2*pre2) << "V" << '\n';
        } else if(l2 == 'P' && l1 == 'I') {
            cout << "U=" << (f2*pre2)/(f1*pre1) << "V" << '\n';
        }
        cout << '\n';
    }
}
