#include <iostream>
using namespace std;

int left(int i) {
	return i << 1;
}

int right(int i) {
	return i << 1 | 1;
}

void build(int *stree, int *arr, int node, int l, int r) {

	if(l == r)
		stree[node] = arr[l];
	else {
		int mid = (l + r) / 2;
		build(stree, arr, left(node), l, mid);
		build(stree, arr, right(node), mid + 1, r);

		stree[node] = stree[left(node)] + stree[right(node)];
	}
}

void update(int *stree, int *arr, int node, int l, int r, int idx, int val) {
	if(l == r){
		arr[idx] = val;
		stree[node] = val;
	} else {

		int mid = (l + r) / 2;
		if(l <= idx && idx <= mid)
			update(stree, arr, left(node), l, mid, idx, val);
		else
			update(stree, arr, right(node), mid + 1, r, idx, val);

		stree[node] = stree[left(node)] + stree[right(node)];
	}
}

int query(int *stree, int node, int l, int r, int a, int b) {
	if(b < l || r < a)
		return 0;
	if(a <= l && r <= b)
		return stree[node];
	
	int mid = (l + r) / 2;
	int p1 = query(stree, left(node), l, mid, a, b);
	int p2 = query(stree, right(node), mid + 1, r, a, b);

	return p1 + p2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, t = 1;
	string op;
	while(cin >> n && n) {
		if(t != 1)
			cout << "\n";

		int *arr = new int[n];
		int *stree = new int[4 * n];
		for(int i=0; i<n; i++) cin >> arr[i];
		build(stree, arr, 1, 0, n - 1);
		cout << "Case " << t++ << ":\n";
		while(cin >> op && op[0] != 'E') {
			cin >> a >> b;
			if(op[0] == 'M') 
				cout << query(stree, 1, 0, n - 1, --a, --b) << '\n';
			else 
				update(stree, arr, 1, 0, n - 1, --a, b);
			
		}
	}
	return 0;
}
