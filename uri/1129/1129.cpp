#include <bits/stdc++.h>
using namespace std;

int main() {
	char op[6] = {'A', 'B', 'C', 'D', 'E', '*'};
	int n, t, k;

	while(cin >> n && n) {
		
		for(int i=0; i<n; i++) {
			k = -1;

			for(int j=0; j<5; j++) {
				cin >> t;
				
				if(t <= 127 && k == -1)
					k = j;
				else if(t <= 127 && k != -1)
					k = 5;
			}
			cout << ((k == -1) ? '*' : op[k]) << '\n';
		}
	}
}