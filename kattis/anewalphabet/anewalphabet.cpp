#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, string> apl;


int main() {
    apl['a'] = "@";
    apl['b'] = "8";
    apl['c'] = "(";
    apl['d'] = "|)";
    apl['e'] = "3";
    apl['f'] = "#";
    apl['g'] = "6";
    apl['h'] = "[-]";
    apl['i'] = "|";
    apl['j'] = "_|";
    apl['k'] = "|<";
    apl['l'] = "1";
    apl['m'] = "[]\\/[]";
    apl['n'] = "[]\\[]";
    apl['o'] = "0";
    apl['p'] = "|D";
    apl['q'] = "(,)";
    apl['r'] = "|Z";
    apl['s'] = "$";
    apl['t'] = "']['";
    apl['u'] = "|_|";
    apl['v'] = "\\/";
    apl['w'] = "\\/\\/";
    apl['x'] = "}{";
    apl['y'] = "`/";
    apl['z'] = "2";

    string word;
    char c;

    getline(cin, word);
    for(int i=0; i<word.size(); i++) {
        c = tolower(word[i]);
        if(islower(c))
            cout << apl[c];
        else
            cout << c;
    }
    cout << '\n';
}
