#include <bits/stdc++.h>
using namespace std;

int module(int a, int b) {
	int ret = a % b;

	if(ret < 0)
		ret += b;

	return ret;
}

int main() {
	int t, s;
	string line;

	cin >> t;
	while(t--) {
		cin >> line >> s;

		for(int i=0; i<line.size(); i++)
			line[i] = module((line[i] - 65) - s, 26) + 65;
		
		cout << line << '\n';
	}
	return 0;
}