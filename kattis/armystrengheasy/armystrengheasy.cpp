#include <bits/stdc++.h>
using namespace std;

typedef multiset<int> mi;

int main() {
	int t, n, m, a;
	string ans;

	cin >> t;

	while(t--) {
		cin >> n >> m;
		mi go, me;

		for(int i=0; i<n; i++){
			cin >> a;
			go.insert(a);
		}

		for(int i=0; i<m; i++){
			cin >> a;
			me.insert(a);
		}

		while(!go.empty() && !me.empty()) {

			if((*go.begin()) < (*me.begin()))
				go.erase(go.begin());
			else
				me.erase(me.begin());
		}

		ans = go.empty() ? "MechaGodzilla" : "Godzilla";
		cout << ans << '\n';
	}
	return 0;
}