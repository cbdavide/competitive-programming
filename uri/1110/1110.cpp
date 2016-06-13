#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;

  while(cin >> n && n){
    queue<int> que;
    vector<int> dis;

    for(int i=1; i<=n; i++)
      que.push(i);

    while(que.size() > 1){
      dis.push_back(que.front());
      que.pop();
      
      que.push(que.front());
      que.pop();
    }

    cout << "Discarded cards: ";
    for(int i=0; i<dis.size(); i++) {
      cout << dis[i];

      if(i < dis.size() - 1)
	cout << ", ";
    }

    cout << "\nRemaining card: " << que.front() << '\n';
  }
  return 0;
}
