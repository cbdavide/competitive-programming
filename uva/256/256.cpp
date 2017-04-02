#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<string> vs;
typedef map<int, vs> mivs;

int main() {
    int n;
    mivs mapa;
    mapa[2] = {"00", "01", "81"};
    mapa[4] = {"0000", "0001", "2025", "3025", "9801"};
    mapa[6] = {"000000", "000001", "088209", "494209", "998001" };
    mapa[8] = {"00000000", "00000001", "04941729", "07441984",
                "24502500", "25502500", "52881984", "60481729",
                "99980001"};
    while(cin >> n) {
        for(int i=0; i<mapa[n].size(); i++)
            cout << mapa[n][i] << '\n';
    }
    return 0;
}
