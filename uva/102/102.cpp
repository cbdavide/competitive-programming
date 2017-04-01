#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

map<int, char> mic;

int main() {
    string l;
    int cont, mini;
    int order[3] = {0, 1, 2};
    mic[0] = 'B'; mic[1] = 'G'; mic[2] = 'C';

    while(getline(cin, l)) {
        stringstream ss(l);
        map<int, string> mis;
        int M[3][3];
        int answ[3] = {0, 0, 0};

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++)
                ss >> M[i][j];
        }

        mini = 1e9;
        do {
            cont = M[0][order[1]] + M[1][order[0]];
            cont += M[0][order[2]] + M[2][order[0]];
            cont += M[1][order[2]] + M[2][order[1]];
            if(cont <= mini) {
                string s;
                s.push_back(mic[order[0]]);
                s.push_back(mic[order[1]]);
                s.push_back(mic[order[2]]);

                if(mis[cont] == "" || mis[cont] > s)
                    mis[cont] = s;

                mini = cont;
            }
        }while(next_permutation(order, order + 3));
        cout << mis[mini] << ' ' << mini << '\n';
    }
    return 0;
}
