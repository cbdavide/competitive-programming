#include <bits/stdc++.h>
using namespace std;

int row[8], board[8][8], maximum;

bool place(int r, int c) {
    for(int prev=0; prev<c; prev++) {
        if(row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return false;
    }
    return true;
}

int backtrack(int c) {
    if(c == 8) {
        int temp = 0;
        for(int i=0; i<8; i++) temp += board[i][row[i]];
        maximum = max(maximum, temp);
    }
    for(int r=0; r<8; r++) {
        if(place(r, c)) {
            row[c] = r;
            backtrack(c + 1);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(row, 0, sizeof row);
        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                scanf("%d", &board[i][j]);
            }
        }
        maximum = -1;
        backtrack(0);
        printf("%5d\n", maximum);
    }
    return 0;
}
