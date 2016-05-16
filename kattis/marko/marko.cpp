#include <iostream>
#include <string>
using namespace std;

string t9[] = {" ", "abc", "def", "ghi", "jkl", "mno", "pqrs",
               "tuv", "wxyz"};

bool is_valid(string word, string s) {
    string tile;

    if(word.size() != s.size())
        return false;

    for(int i=0; i<word.size(); i++) {
        tile = t9[(s[i] - 48) - 1];
        if(tile.find(word[i]) == string::npos)
            return false;
    }

    return true;
}

main() {
    int n, cont = 0;
    string *dic, s;

    cin >> n;
    dic = new string[n];

    for(int i=0; i<n; i++)
        cin >> dic[i];

    cin >> s;
    for(int i=0; i<n; i++) {
        if(is_valid(dic[i], s))
            cont++;
    }

    cout << cont << '\n';

}
