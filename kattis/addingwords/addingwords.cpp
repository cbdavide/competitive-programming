#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int operate(int a, char sign, int b) {
    if (sign == '+')
        return a + b;

    return a - b;
}

string find_key(int val, map<string, int> table) {
    map<string, int>::iterator i = table.begin();

    for( ; i != table.end(); i++) {
        if((*i).second == val)
            return (*i).first;
    }

    return "unknown";
}

void process(string line, map<string, int> table) {
    stringstream ss(line);
    bool cond = true;
    int result = 0;
    char sign = '+';
    string name;

    while(sign != '=') {
        ss >> name;
        if(!table.count(name)) {
            cond = false;
            break;
        }

        result = operate(result, sign, table[name]);
        ss >> sign;
    }
    cout << line << ' ';
    if(cond)
        cout << find_key(result, table) << '\n';
    else
        cout << "unknown\n";
}

int main() {
    string line, operacion, name, body;
    int value;
    map<string, int> table;

    while (getline(cin, line)) {
        stringstream ss(line);

        ss >> operacion;

        if (operacion == "def") {
            ss >> name >> value;
            table[name] = value;
        }

        else if(operacion == "clear") {
            table.clear();
        }

        else if(operacion == "calc") {
            getline(ss, body);
            body.erase(body.begin());

            process(body, table);
        }
    }

    return 0;
}
