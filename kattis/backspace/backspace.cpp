#include <iostream>
#include <string>
using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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
