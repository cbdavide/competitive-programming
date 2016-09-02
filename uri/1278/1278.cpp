#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<vs> vss;

int computeMax(vss mat) {
	int max = 0, cont;
	
	for(int i=0; i<mat.size(); i++){
		cont = 0;
		
		for(int j=0; j<mat[i].size(); j++)
			cont += mat[i][j].size();

		cont += mat[i].size() - 1;

		if(cont > max)
			max = cont;
	}

	return max;
}

string build(vs arr) {
	string answ = "";

	for(int i=0; i<arr.size(); i++){
		answ += arr[i];

		if(i != arr.size() - 1)
			answ += " ";
	}
	return answ;
}

int main(){
	int n, max;
	string line, word;
	bool cond = 0;
	
	while(cin >> n && n){
		getline(cin, line);

		vss lines;
	
		for(int i=0; i<n; i++) {
			vs words;
			
			getline(cin, line);
			stringstream ss(line);

			while(ss >> word)
				words.push_back(word);

			lines.push_back(words);
		}

		max = computeMax(lines);

		if(cond)
			cout << '\n';
		else
			cond = 1;
		
		for(int i=0; i<lines.size(); i++) {

			word = build(lines[i]);			
			cout << right << setw(max) << word << '\n';			
		}
	}
	return 0;
}
