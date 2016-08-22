#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, h;
	string line;

	cin >> n;
	getline(cin, line);

	for(int i=0; i<n; i++) {
		getline(cin, line);

		for(int j=0; j<line.size(); j++) {
			if(islower(line[j]) || isupper(line[j]))
				line[j] += 3;
		}

		reverse(line.begin(), line.end());

		h = floor(line.size() / 2);
		for(int j=h; j<line.size(); j++) {
			line[j] -= 1;
		}
		
		cout << line << '\n';
	}
	return 0;
}