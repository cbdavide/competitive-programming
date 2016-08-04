#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n, m;

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> m;
		vi arr(m);

		for(int j=0; j<m; j++)
			cin >> arr[j];

		sort(arr.begin(), arr.end());

		for(int j=0; j<arr.size(); j++) {
			cout << arr[j];

			if(j != arr.size() - 1)
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}