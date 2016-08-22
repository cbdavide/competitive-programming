#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, nled[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, cont;
	string num;

	cin >> t;
	while(t--) {
		cin >> num;
		cont = 0;
		
		for(int i=0; i<num.size(); i++)
			cont += nled[num[i] - 48];

		cout << cont << " leds\n";
	}
	return 0;
}