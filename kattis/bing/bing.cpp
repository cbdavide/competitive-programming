#include <bits/stdc++.h>
using namespace std;

struct node {
    node* children[26];
    int prefix, words;
    bool is_end;

    node() {
        memset(children, 0, sizeof(children));
        is_end = false;
        prefix = words = 0;
    }
};

void insert(node *nd, string::iterator s) {
    if(*s) {
        nd->prefix += 1;
        if(!nd->children[*s - 'a'])
            nd->children[*s - 'a'] = new node();
        insert(nd->children[*s - 'a'], s + 1);
    } else {
        nd->is_end = true;
        nd->words += 1;
    }
}

int countWords(node *nd, string::iterator s) {
    if(*s) {
        if(!nd->children[*s - 'a'])
            return 0;
        return countWords(nd->children[*s - 'a'], s + 1);
    } else {
        return nd->words;
    }
}

int countPre(node *nd, string::iterator s) {
    if(*s) {
        if(!nd->children[*s - 'a'])
            return 0;

        return countPre(nd->children[*s - 'a'], s + 1);
    } else {
        return nd->prefix;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cont, r;
    string *words, temp;

    while(cin >> n) {
        words = new string[n];
        node *trie = new node();

        for(int i=0; i<n; i++) {
            cin >> words[i];
            r = countPre(trie, words[i].begin()) + countWords(trie, words[i].begin());
            cout << r << '\n';
            insert(trie, words[i].begin());
        }
    }
    return 0;
}
