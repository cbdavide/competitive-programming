#include <bits/stdc++.h>
using namespace std;

string findFriend(queue<string> list) {
  int max = 0;
  string name = "";

  while(!list.empty()){
    if(list.front().size() > max) {
      max = list.front().size();
      name = list.front();
    }
    list.pop();
  }
  
  return name;
}

int main() {
  string name, option, amigo;
  queue<string> friends;
  set<string> friendsList, unfriendsList;
  set<string>::iterator i;
  
  while(cin >> name && name != "FIM") {
    cin >> option;

    if(option == "YES"){
      friends.push(name);
      friendsList.insert(name);
    }else {
      unfriendsList.insert(name);
    }
  }

  amigo = findFriend(friends);

  i = friendsList.begin();
  for( ; i != friendsList.end(); i++)
    cout << (*i) << '\n';
  
  i = unfriendsList.begin();
  for( ; i != unfriendsList.end(); i++)
    cout << (*i) << '\n';
  
  cout << "\nAmigo do Habay:\n" << amigo << '\n';

  return 0;
}
