#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n, q, t, a, b;

	while(cin >> n >> q){
		vii el(1000010, vi());

		for(int i=1; i<=n; i++) {
			cin >> t;
			el[t].push_back(i);
		}

		for(int i=0; i<q; i++) {
			cin >> a >> b;

			if(a <= el[b].size())
				cout << el[b][a - 1] << '\n';
			else
				cout << "0\n";
		}
	}
	return 0;
}