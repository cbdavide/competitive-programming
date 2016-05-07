#include <iostream>
#include <string>
using namespace std;

main() {
    char c;
    string result;

    while(cin.get(c)) {
        if(c == '<')
            result.pop_back();
        else
            result.push_back(c);
    }

    cout << result << '\n';
}
