#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	int proc, step, cycles, i, rest;

	while(cin >> line >> proc){
		step = cycles = 0;

		for(i=0; i<line.size(); i++){

			if(line[step] != line[i]) {
				
				if(line[step] == 'W'){
					cycles += (i - step);
				} else{
					rest = ((i - step) % proc) ? 1 : 0;
					cycles += ((i - step) / proc) + rest;
				}

				step = i;
			}	
		}

		if(line[step] == 'W') {
			cycles += (i - step);
		} else{
			rest = ((i - step) % proc) ? 1 : 0;
			cycles += ((i - step) / proc) + rest;
		} 

		cout << cycles << '\n';
	}
	return 0;
}