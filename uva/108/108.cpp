#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int main() {
	int n;
	cin >> n;
	int A[n][n];
	memset(A, 0, sizeof(int)* n * n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++){
			cin >> A[i][j];
			if(i > 0) A[i][j] += A[i - 1][j];
			if(j > 0) A[i][j] += A[i][j - 1];
			if(i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
		}
	}
	int answ = -INF;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			for(int k=i; k<n; k++) {
				for(int l=j; l<n; l++) {
					int sub = A[k][l];
					if(i > 0) sub -= A[i - 1][l];
					if(j > 0) sub -= A[k][j - 1];
					if(i > 0 && j > 0) sub += A[i - 1][j - 1];
					answ = max(answ, sub);
				}
			}
		}
	}
	cout << answ << '\n';
	return 0;
}
