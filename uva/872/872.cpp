#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T &x) {return x.size();}
template <class T> T mod(T a, T b) { return (b + (a % b)) % b;}

#define F first
#define S second
#define PB push_back
#define endl '\n'
#define rep(i, a, b) for(__typeof(a) i=a; i<(b); i++)
#define iter(it, c) for(__typeof((c).begin()) it=(c).begin(); \
 it != (c).end(); it++)

typedef vector<char> vc;
typedef set<char> sc;
typedef map<char, sc> csc;
typedef map<char, int> csi;
typedef map<char, bool> cb;

csc G; csi indegree;
cb vis; vc res;
int cont = 0;

void all_topsort() {
    bool flag = false;
    iter(it, G) {
        char v = (*it).F;
        sc list = (*it).S;

        if(!indegree[v] && !vis[v]) {
            iter(otr, list) indegree[*otr]--;

            res.PB(v);
            vis[v] = true;

            all_topsort();

            res.pop_back();
            vis[v] = false;

            iter(otr, list) indegree[*otr]++;

            flag = true;
        }
    }

    if(!flag) {
        if(!size(res)) return;
        cont++;
        rep(i, 0, size(res)) {
            cout << res[i];

            if(i < size(res) - 1)
                cout << ' ';
        }
        cout << endl;
    }
}

int main() {
    char a, b, c, z = 1;
    int t;
    string line, line2;
    
    cin >> t;
    cin.ignore();
    cin.ignore();

    while(t--) {
        if(z++ > 1) cout << endl;

        cont = 0;
        G.clear(); indegree.clear();
        vis.clear(); res.clear();
        
        getline(cin, line);
        stringstream ss(line);
        while(ss >> c) G[c];

        getline(cin, line2);
        stringstream tt(line2);
        while(tt >> a >> b >> c){
            G[a].insert(c);
            indegree[c]++;
        }
        
        all_topsort();
        if(!cont) cout << "NO" << endl;
        cin.ignore();
    }
    return 0;
}