#include <bits/stdc++.h>
using namespace std;

struct node {
    int prefix;
    node* children[10];
    node() {
        memset(children, 0, sizeof(children));
        prefix = 0;
    }
};

void insert(node *nd, string::iterator s)  {
    if(*s) {
        nd->prefix += 1;
        if(!nd->children[*s - '0'])
            nd->children[*s - '0'] = new node();
        insert(nd->children[*s - '0'], s + 1);
    }
}

int countPrefix(node *nd, string::iterator s) {
    if(*s) {
        if(!nd->children[*s - '0'])
            return 0;
        return countPrefix(nd->children[*s - '0'], s + 1);
    } else {
        return nd->prefix;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    string *numbers;

    cin >> t;
    while(t--) {
        cin >> n;
        bool cond = true;

        numbers = new string[n];
        for(int i=0; i<n; i++) cin >> numbers[i];

        node *trie = new node();

        for(int i=0; i<n; i++) {
            insert(trie, numbers[i].begin());
        }

        for(int i=0; i<n; i++) {
            if(countPrefix(trie, numbers[i].begin()) > 0) {
                cond = false;
                break;
            }
        }

        if(cond) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
