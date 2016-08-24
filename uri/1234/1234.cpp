#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;

	while(getline(cin, s)) {
		bool state = 1;

		for(int i=0; i<s.size(); i++) {
			
			if(s[i] != ' ') {

				if(state) {
					s[i] = toupper(s[i]);
					state = 0;
				} else {
					s[i] = tolower(s[i]);
					state = 1;
				}

			}
		}

		cout << s << '\n';
	}
	return 0;
}