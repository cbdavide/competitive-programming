#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s[3];
	cin >> n >> s[0] >> s[1] >> s[2];

	int dir[n + 1];
	memset(dir, -1, sizeof(int) * (n + 1));
	dir[0] = 0;
	
	for(int i=1; i<=n; i++) {
		int q = -1;

		for(int j=0; j<3; j++) {
			
			if(s[j] <= i)
				q = max(q, dir[i - s[j]]);				
		}

		dir[i] = q != -1 ? q + 1 : q;
	}

	cout << dir[n] << '\n';
	return 0;
}
