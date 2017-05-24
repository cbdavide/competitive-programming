#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;


struct union_find {
	vi data, pe;
	union_find(int n) : data(vi(n)), pe(vi(n, 1)) {
		for(int i=0; i<data.size(); i++) data[i] = i;
	}
	int find(int x) {
		if(x == data[x]) return x;
		data[x] = find(data[x]);
		return data[x];
	}
	bool unite(int x, int y) {
		int px = find(x), py = find(y);
		if(px == py) return false;
		if(pe[px] > pe[py]) swap(px, py);
		pe[px] += pe[py];
		data[py] = px;
		return true;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, x, y, good, bad;
	string line;
	char c;
	vii answ;
	cin >> t;
	while(t--) {
		good = bad = 0;
		cin >> n;
		cin.ignore();
		union_find set(n + 1);
		while(getline(cin, line) && line != "") {
			stringstream ss(line);
			ss >> c >> x >> y;
			if(c == 'c') set.unite(x, y);
			else {
				if(set.find(x) == set.find(y)) good++;
				else bad++;
			}
		}
		answ.push_back(ii(good, bad));
	}
	for(int i=0; i<answ.size(); i++) {
		cout << answ[i].first << ',' << answ[i].second << '\n';
		if(i < (int)answ.size() - 1)  cout << '\n';
	}
	return 0;
}
