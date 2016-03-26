#include <bits/stdc++.h>
using namespace std;

main() {
    int nDays;
    string day;
    while(cin >> nDays && nDays > 0) {
        getline(cin, day);
        map<string, vector<string> > data;
        for(int i=0; i<nDays; i++) {
            string name, buf;

            getline(cin, day);

            stringstream ss(day);
            ss >> name;
            while(ss >> buf)
                data[buf].push_back(name);
        }
        map<string, vector<string> >::iterator i;
        for(i = data.begin(); i != data.end(); i++) {
            sort((*i).second.begin(), (*i).second.end());
            cout << (*i).first << " ";
            vector<string>::iterator j;
            for(j=(*i).second.begin(); j != (*i).second.end()-1; j++) {
                cout << *j << " ";
            }
            cout << *j << '\n';
        }
        cout << '\n';
    }
}
