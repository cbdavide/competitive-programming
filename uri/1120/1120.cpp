#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;

	while(cin >> a >> b && a != "0" && b != "0") {
		
		string::iterator i;
		for(i = b.begin(); i != b.end(); ) {
			
			if(a[0] == (*i))
				b.erase(i);
			else 
				i++;
		}

		for(i = b.begin(); ((i != b.end()) && ((*i) == '0')); )
			b.erase(i);

		cout << ((b != "") ? b : "0") << '\n';
	}
	return 0;
}