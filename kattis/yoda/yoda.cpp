#include <iostream>
#include <string>

using namespace std;

int main() {
    string n1, n2;
    string o1 = "", o2 = "";
    char a, b;
    cin >> n1 >> n2;

    int i = n1.size() - 1;
    int j = n2.size() - 1;
    for( ; i >= 0 || j >= 0; i--, j--) {
        a = i >= 0 ? n1[i] : '0';
        b = j >= 0 ? n2[j] : '0';

        if(a == b) {
            o1.insert(0, 1, a);
            o2.insert(0, 1, b);
        } else if(a > b) {
            o1.insert(0, 1, a);
        } else {
            o2.insert(0, 1, b);
        }
    }

    if(o1 != "")
        cout << stoi(o1) << '\n';
    else
        cout << "YODA\n";
    if(o2 != "")
        cout << stoi(o2) << '\n';
    else
        cout << "YODA\n";

    return 0;
}
