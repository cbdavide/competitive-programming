#include <bits/stdc++.h>
using namespace std;

main() {
    int n, k;
    int p1, p2;
    string m1, m2;
    cin >> n >> k;
    
    cout << setprecision(3);
    cout << fixed;
    
    while(n) {
        double playerWin[n], playerLose[n];
        
        for(int i=0; i<n; i++)
            playerWin[i] = playerLose[i] = 0;
           
        for(int i=0; i<((n*k)*(n-1))/2; i++) {
            cin >> p1 >> m1 >> p2 >> m2;
            
           if(m1[0] == 'p' && m2[0] == 'r') {//p1 wins
               playerWin[p1-1]++;
               playerLose[p2-1]++;//Increment lose
           } else if(m1[0] == 's' && m2[0] == 'p') {
               playerWin[p1-1]++;
               playerLose[p2-1]++;
           } else if(m1[0] == 'r' && m2[0] == 's') {
               playerWin[p1-1]++;
               playerLose[p2-1]++;
           } else if(m1[0] == 'r' && m2[0] == 'p') {//p1 lose
               playerLose[p1-1]++;
               playerWin[p2-1]++;
           } else if(m1[0] == 'p' && m2[0] == 's') {
               playerLose[p1-1]++;
               playerWin[p2-1]++;
           } else if(m1[0] == 's' && m2[0] == 'r') {
               playerLose[p1-1]++;
               playerWin[p2-1]++;
           }
        }

        for(int i=0; i<n; i++) {
            if(playerWin[i] + playerLose[i] == 0)
                cout << "-" << endl;
             else
                cout << playerWin[i]/(playerWin[i] + playerLose[i]) << endl;
        }
        cin >> n >> k;
        if(n !=0 )
            cout << '\n';    
    }    
}