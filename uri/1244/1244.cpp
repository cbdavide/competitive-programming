#include <bits/stdc++.h>
using namespace std;

bool sorti(pair<string, int> a, pair<string, int> b) {
	if(a.first.size() > b.first.size())
		return true;
	else if(a.first.size() == b.first.size() && a.second < b.second)
		return true;

	return false;
}

int main() {
	string s, a;
	int t;
	cin >> t;
	getline(cin, a);
	while(t--) {
		vector<pair<string, int> > vs;
		getline(cin, s);
		stringstream ss(s);
		int i = 1;
		while(ss >> a)
			vs.push_back(pair<string, int>(a, ++i));

		sort(vs.begin(), vs.end(), sorti);
		for(int i=0; i<vs.size(); i++) {
			cout << vs[i].first;

			if(i < vs.size() - 1)
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
