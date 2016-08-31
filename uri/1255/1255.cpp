#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int findMax(vi arr) {
	int i = 0;
	
	for(int j=1; j<arr.size(); j++){
		if(arr[j] > arr[i])
			i = j;
	}

	return arr[i];
}

int main() {
	int t, max;
	string line;
	char c;

	cin >> t;
	getline(cin, line);

	while(t--){
		vi list(26, 0);
		getline(cin, line);

		for(int i=0; i<line.size(); i++){
			c = tolower(line[i]);

			if(islower(c)){
				list[c - 97]++;
			}
		}

		max = findMax(list);
		for(int i=0; i<list.size(); i++){
			if(list[i] == max)
				cout << (char)(i + 97);
		}
		cout << '\n';
	}
	return 0;
}