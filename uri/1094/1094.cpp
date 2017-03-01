#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, cont = 0;
    char c;
    map <char, int> mapa;

    cin >> t;
    while(t--) {
        cin >> a >> c;
        mapa[c] += a;
        cont += a;
    }

    cout << "Total: " << cont << " cobaias\n";
    cout << "Total de coelhos: " << mapa['C'] << '\n';
    cout << "Total de ratos: " << mapa['R'] << '\n';
    cout << "Total de sapos: " << mapa['S'] << '\n';
    printf("Percentual de coelhos: %.2f \%\n", ((float)mapa['C'] / cont) * 100);
    printf("Percentual de ratos: %.2f \%\n", ((float)mapa['R'] / cont) * 100);
    printf("Percentual de sapos: %.2f %\n", ((float)mapa['S'] / cont) * 100);

    return 0;
}
