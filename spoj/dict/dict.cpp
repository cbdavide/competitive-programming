#include <bits/stdc++.h>
using namespace std;

typedef string::iterator sitr;

struct node {
    node* children[26];
    bool is_end;
    node() {
        memset(children, 0, sizeof(children));
        is_end = false;
    }
};

void insert(node *nd, sitr s) {
    if(*s) {
        if(!nd->children[*s - 'a'])
            nd->children[*s - 'a'] = new node();
        insert(nd->children[*s - 'a'], s + 1);
    } else nd->is_end = true;
}

void traverse(node *nd, string t = "", bool cond = 0) {
    if(!nd) return;

    if(nd->is_end && cond)
        cout << t << endl;

    for(int i=0; i<26; i++) {
        if(nd->children[i]) {
            cond = true;
            traverse(nd->children[i], t + (char)(i + 'a'), 1);
        }
    }

    if(!cond) cout << "No match.\n";
}

void find(node *nd, sitr s, string &word) {
    if(*s) {
        if(!nd->children[*s - 'a']) {
            cout << "No match.\n";
            return;
        } else {
            find(nd->children[*s - 'a'], s + 1, word);
        }
    } else {
        traverse(nd, word);
        if(nd->is_end) {
        }
    }
}

int main() {
    int n, q;
    string s;

    node *trie = new node();
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> s;
        insert(trie, s.begin());
    }

    cin >> q;
    for(int i=1; i<=q; i++) {
        cin >> s;
        cout << "Case #" << i << ":\n";
        find(trie, s.begin(), s);
    }
    return 0;
}
