#include <bits/stdc++.h>
using namespace std;

int main() {

	string line;
	
	while(getline(cin, line)) {
		
		for(int i=0; i<line.size(); i++) {
			
			if(islower(line[i]))
				line[i] = (((line[i] - 97) + 13 ) % 26) + 97;
			else if(isupper(line[i]))
				line[i] = (((line[i] - 65) + 13) % 26) + 65;
		}
		
		cout << line << '\n';
	}
	return 0;
}