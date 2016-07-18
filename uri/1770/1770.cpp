#include <bits/stdc++.h>
using namespace std;

typedef set<int> si;
typedef vector<int> vi;

int main() {
  int s, p, t, total, i;

  while(cin >> s >> p){
    total = 0;
    vi songs(s);
    si tracks;

    for(i=0; i<s; i++)
      cin >> songs[i];

    for(i=0; i<p; i++) {
      cin >> t;
      tracks.insert(t);
      total += songs[t - 1];

      if(tracks.size()  == s)
	break;
    }
    ++i;
    for( ; i<p; i++)
      cin >> t;

    if(tracks.size() < s)
      cout << "-1\n";
    else
      cout << total << '\n';

  }
  return 0;
}
