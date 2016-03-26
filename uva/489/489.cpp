#include <bits/stdc++.h>
using namespace std;

main() {
    
    int round, wrong, i;
    string word, guess, answer;    
    bool cond;
     
    while(cin >> round && round != -1) {
     
        cin >> word;
        cin >> guess;
        
        wrong = 0;
        i = 0;
        
        while(i<guess.size() && word != ""  && wrong < 7) {
            if(word.find(guess[i]) != string::npos) {
                word.erase(remove(word.begin(), word.end(), guess[i]), word.end());
            } else {
                ++wrong;
            }
            i++;
        }
        
        if(wrong == 7) {
            answer = "You lose.";
        } else if(word == "") {
            answer = "You win.";
        } else {
            answer = "You chickened out.";
        }

        cout << "Round " << round << '\n';
        cout << answer << '\n';
    }     
}