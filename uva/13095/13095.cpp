#include <iostream>
#include <bitset>
using namespace std;

int size(int n) {
	bitset<16> conjunto(n);
	return conjunto.count();
}

int left(int i){
	return i << 1;
}

int right(int i) {
	return i << 1 | 1;
}

void build(int *stree, int *arr, int node, int l, int r) {
	if(l == r) {
		stree[node] = 1 << arr[l];
	}else {
		int m = (l + r) / 2;
		build(stree, arr, left(node), l, m);
		build(stree, arr, right(node), m + 1, r);

		//JOINED
		stree[node] = stree[left(node)] | stree[right(node)];
	}
}

int query(int *stree, int node, int l, int r, int i, int j) {

	if(i > r || j < l)
		return -1;

	if(l >= i && r <= j)
		return stree[node];

	int m = (l + r) / 2;
	int p1 = query(stree, left(node), l, m, i, j);
	int p2 = query(stree, right(node), m + 1, r, i, j);

	if(p1 == -1)
		return p2;
	if(p2 == -1)
		return p1;

	return p1 | p2;

}


int main() {
	int n, q, l, r, *stree, *arr, conjunto;
	while(cin >> n) {
		arr = new int[n];
		stree = new int[4 * n];
		for(int i=0; i<n; i++) cin >> arr[i];
		build(stree, arr, 1, 0, n - 1);

		cin >> q;
		while(q--) {
			cin >> l >> r;
			conjunto = query(stree, 1, 0, n - 1, --l, --r);
			cout << size(conjunto) << '\n';
		}
		
	}

	return 0;
}
