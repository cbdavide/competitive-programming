#include <bits/stdc++.h>
using namespace std;

typedef deque<string> arr;

void saveWord(arr &a, char c, string w) {
	if(c == '[')
		a.push_front(w);
	else
		a.push_back(w);
}

int main() {
	string line, temp, answ;
	char ant = ']';

	while(getline(cin, line)){
		ant = ']';
		temp = answ = "";
		arr words;

		for(int i=0; i<line.size(); i++) {
			if(line[i] == '[' || line[i] == ']') {
				saveWord(words, ant, temp);
				ant = line[i];
				temp = "";
			} else {
				temp.push_back(line[i]);
			}
		}

		saveWord(words, ant, temp);

		for(int i=0; i<words.size(); i++)
			answ += words[i];

		cout << answ << '\n';
	}
	return 0;
}