#include <bits/stdc++.h>
using namespace std;

int preIndex = 0;

struct node {
    char key;
    node *left, *right;

    node(int k) {
        key = k;
        left = NULL;
        right = NULL;
    };
};

void postorder(node *root) {
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->key;
}

int search(string word, int b, int e, char c) {
    for(int i=b; i<=e; i++) {
        if(word[i] == c)
            return i;
    }
    return -1;
}

node* build(string in, string pre, int b, int e) {

    if(b > e)
        return NULL;

    node *root = new node(pre[preIndex++]);

    if(b == e)
        return root;

    int inIndex = search(in, b, e, root->key);

    root->left = build(in, pre, b, inIndex - 1);
    root->right = build(in, pre, inIndex + 1, e);

    return root;
}

int main() {
    string pre, in;
    node *tree;

    while(cin >> pre >> in) {
        tree = build(in, pre, 0, pre.size() - 1);
        preIndex = 0;
        postorder(tree);
        cout << '\n';
    }

    return 0;
}
