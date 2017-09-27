#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef queue<string> qs;
typedef pair<string, string> ss;
typedef pair<int, ss> record;

bool cmp(record &a, record &b) {
    return a.F < b.F;
}

void match(ss &teamW, ss &teamB, qs &q, char c) {
    if(c == 'W') {
        swap(teamW.F, teamW.S);
        swap(teamB.F, teamB.S);
        string temp = q.front(); q.pop();
        q.push(teamB.F);
        teamB.F = temp;
    } else {
        swap(teamB.F, teamB.S);
        swap(teamW.F, teamW.S);
        string temp = q.front(); q.pop();
        q.push(teamW.F);
        teamW.F = temp;
    }
}

int main() {
    int n;
    string temp, games;
    ss teamW, teamB;
    while(cin >> n) {
        qs q;
        cin >> teamW.F >> teamB.F;
        cin >> teamW.S >> teamB.S;
        for(int i=0; i<n-4; i++) {
            cin >> temp;
            q.push(temp);
        }
        cin >> games;

        vector<record> winners;
        ss team = (games[0] == 'W') ? teamW : teamB;
        int cont = 1;

        match(teamW, teamB, q, games[0]);

        for(int i=1; i<games.size(); i++) {
            //Game Logic
            if(games[i] == games[i - 1]) {
                cont++;
            } else {

                if(winners.size() > 0)
                    winners.push_back(record(cont, ss(team.S, team.F)));
                else
                    winners.push_back(record(cont, team));

                team = (games[i] == 'W') ? teamW : teamB;
                cont = 1;
            }

            match(teamW, teamB, q, games[i]);

        }

        if(winners.size() > 0)
            winners.push_back(record(cont, ss(team.S, team.F)));
        else
            winners.push_back(record(cont, team));

        int maxi = -1;
        for(int i=0; i<winners.size(); i++)
            maxi = max(maxi, winners[i].F);

        for(int i=0; i<winners.size(); i++)
            if(maxi == winners[i].F)
                cout << winners[i].S.F << ' ' << winners[i].S.S << '\n';

    }
    return 0;
}
