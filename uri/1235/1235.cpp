#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, half;
	string line;

	cin >> t;
	getline(cin, line);
	
	while(t--) {
		getline(cin, line);

		half = line.size() / 2;
		reverse(line.begin(), line.begin() + half);
		reverse((line.begin() + half), line.end()); 
		
		cout << line << '\n';
	}
	return 0;
}