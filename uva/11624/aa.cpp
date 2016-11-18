// http://uva.onlinejudge.org/external/116/11624.html
// Runtime: .508s
// Tag: Bfs


/*
 * File:   main.cpp
 * Author: shahab
 * Created on April 1, 2011, 3:43 PM
 */

// @BEGIN_OF_SOURCE_CODE

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define pi acos(-1.0)
#define N 1000000
#define LL long long

#define For(i, a, b) for ( int i = (a); i < (b); i++ )
#define Fors(i, sz) for ( size_t i = 0; i < sz.size (); i++ )
#define Set(a, s) memset (a, s, sizeof (a))

using namespace std;

struct state {
    int x;
    int y;
    int c;

    state (int p, int q, int r) {
        x = p;
        y = q;
        c = r;
    }

    state () { }
} a;

int row, col;
char matrix [1000 + 5] [1000 + 5];
int cost_joe [1000 + 5] [1000 + 5];
int cost_fire [1000 + 5] [1000 + 5];
int dr [] = {-1, 0, 1, 0};
int dc [] = {0, 1, 0, -1};

void bfs_for_joe (int r, int c)
{
    queue <state> q;
    cost_joe [r] [c] = 0;
    q.push(state (r, c, 0));

    while ( !q.empty() ) {
        a = q.front(); q.pop();

        for ( int i = 0; i < 4; i++ ) {
            int nx = a.x + dr [i];
            int ny = a.y + dc [i];
            if ( nx >= 0 && nx < row && ny >= 0 && ny < col && matrix  [nx] [ny] != '#' && cost_joe [nx] [ny] == INF_MAX ) {
                cost_joe [nx] [ny] = a.c + 1;
                q.push(state (nx, ny, a.c + 1));
            }
        }
    }
}

void bfs_for_fire ()
{
    queue <state> q;

    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j < col; j++ ) {
            if ( matrix [i] [j] == 'F' ) {
                cost_fire [i] [j] = 0;
                q.push(state (i, j, 0));
            }
        }
    }

    while ( !q.empty() ) {
        a = q.front(); q.pop();

        for ( int i = 0; i < 4; i++ ) {
            int nx = a.x + dr [i];
            int ny = a.y + dc [i];
            if ( nx >= 0 && nx < row && ny >= 0 && ny < col && matrix  [nx] [ny] != '#' && cost_fire [nx] [ny] > a.c + 1) {
                cost_fire [nx] [ny] = a.c + 1;
                q.push(state (nx, ny, a.c + 1));
            }
        }
    }
}

void reset ()
{
    for ( int i = 0; i < 1005; i++ ) {
        for ( int j = 0; j < 1005; j++ )
            cost_joe [i] [j] = cost_fire [i] [j] = INF_MAX;
    }
}


int main(int argc, char** argv)
{
    //freopen ("in.txt", "r", stdin);
    //freopen ("out.txt", "w", stdout);

    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        scanf ("%d %d", &row, &col);

        for ( int i = 0; i < row; i++ ) scanf ("%s", matrix [i]);

        reset ();

        for ( int i = 0; i < row; i++ ) {
            for ( int j = 0; j < col; j++ ) {
                if ( matrix [i] [j] == 'J' ) {
                    bfs_for_joe (i, j);
                    i = row;
                    j = col;
                }
            }
        }

        bfs_for_fire();

        for (size_t i = 0; i < row; i++) {
          for (size_t j = 0; j < col; j++) {
            cout << cost_fire[i][j] << ' ';
          }cout << endl;
        }

        int minimum_escape_time = INF_MAX;

        // 1st & last row
        for ( int i = 0; i < col; i++ ) {
            if ( cost_fire [0] [i] > cost_joe [0] [i] ) minimum_escape_time = min (minimum_escape_time, cost_joe [0] [i]);
            if ( cost_fire [row - 1] [i] > cost_joe [row - 1] [i] ) minimum_escape_time = min (minimum_escape_time, cost_joe [row - 1] [i]);
        }

        // 1st & last col
        for ( int i = 0; i < row; i++ ) {
            if ( cost_fire [i] [0] > cost_joe [i] [0] ) minimum_escape_time = min (minimum_escape_time, cost_joe [i] [0]);
            if ( cost_fire [i] [col - 1] > cost_joe [i] [col - 1] ) minimum_escape_time = min (minimum_escape_time, cost_joe [i] [col - 1]);
        }

        if ( minimum_escape_time == INF_MAX ) printf ("IMPOSSIBLE\n");
        else printf ("%d\n", minimum_escape_time + 1);

    }

    return 0;
}

// @END_OF_SOURCE_CODE
