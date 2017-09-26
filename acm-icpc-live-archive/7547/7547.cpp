#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef set<ll> si;

vi build(int n, int L, int a, int b, int g1) {
	si answ;
	answ.insert(0LL); answ.insert((ll)g1);
	ll last = (ll)g1;
	for(int i=2; i<=n; i++) {
		last = (((ll)a * last) + b) % (L + 1);
		answ.insert(last);
	}

	vi temp(answ.begin(), answ.end());
	return temp;
 }

ll findtop(vi &sqc, int n) {
	vi::iterator idx = lower_bound(sqc.begin(), sqc.end(), (ll)n - 1);
	if(idx == sqc.end()) return (ll)n - 1;
	if(*idx == (n - 1)) return (ll)n - 1;
	return *(--idx);
}

int badness(vi &seq, ll last) {
	if(last < seq[1]) return 0;
	int bad = seq[1] - seq[0] - 1LL, i = 2;

	for( ; i<seq.size() && seq[i] <= last; i++)  {
		bad = max(bad, (int)(seq[i] - seq[i - 1] - 1LL));
	}
	
	if(i < last) bad = max(bad, (int)last - (int)seq.back());
	return bad;
}

int main() {
	int k, n, L, a, b, g1, w;
	while(cin >> k >> n >> L >> a >> b >> g1) {
		vi seq = build(n, L, a, b, g1);

		for(int i=0; i<k; i++) {
			cin >> w;
			ll last = findtop(seq, w);
			cout << badness(seq, last) << '\n';

		}

	}
	return 0;
}
