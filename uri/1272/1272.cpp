#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	string line, word, answ;

	cin >> t;
	getline(cin, line);

	while(t--) {
		answ = "";
		getline(cin, line);

		stringstream ss(line);
		while(ss >> word)
			answ.push_back(word[0]);

		cout << answ << '\n';
	}
	return 0;
}