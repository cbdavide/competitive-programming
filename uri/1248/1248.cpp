#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string diet, a, b, total;
	bool cond;

	cin >> t;
	getline(cin, diet);

	while(t--) {
		cond = true;
		set<char> list;

		getline(cin, diet);
		getline(cin, a);
		getline(cin, b);

		total = a + b;

		for(int i=0; i<diet.size(); i++)
			list.insert(diet[i]);

		for(int i=0; i<total.size(); i++) {
			if(list.erase(total[i]) != 1) {
				cond = false;
				break;
			}
		}

		if(!cond) {
			cout << "CHEATER\n";
		} else {
			
			set<char>::iterator i = list.begin();
			for( ; i != list.end(); i++)
				cout << (*i);

			cout << '\n';
		}
		

	}
	return 0;
}