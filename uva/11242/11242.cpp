#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;

int main() {
	int n, m;
	while(cin >> n && n) {
		cin >> m;

		vi f(n), b(m);
		
		for(int i=0; i<n; i++) cin >> f[i];
		for(int i=0; i<m; i++) cin >> b[i];

		vd results;

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				results.push_back((double)b[j] / f[i]);
			}
		}

		sort(results.begin(), results.end());
		double maxi = 0.0;
		for(int i=0; i<(int)results.size() - 1; i++) {
			//printf("%.2f ", results[i + 1] / results[i]);
			maxi = max(maxi, results[i + 1] / results[i]);
		} //cout << endl;
		
		printf("%.2f\n", maxi);		
	}
	return 0;		
}
