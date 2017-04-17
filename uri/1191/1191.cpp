#include <bits/stdc++.h>
using namespace std;

struct node {
    char val;
    node *left, *right;
    node(char _val) : val(_val), left(NULL), right(NULL) {};
};

int preIndex = 0;

int search(string &word, int b, int c, char val) {
    for(int i=b; i<=c; i++) {
        if(word[i] == val) return i;
    }
    return -1;
}

node* build(string &in, string &pre, int b, int e) {
    if (b > e) return NULL;
    node *root = new node(pre[preIndex++]);
    if(b == e) return root;
    int mid = search(in, b, e, root->val);
    root->left = build(in, pre, b, mid - 1);
    root->right = build(in, pre, mid + 1, e);
    return root;
}

void postorder(node *root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val;
}

int main() {
    string pre, in;
    node *tree = NULL;
    while(cin >> pre >> in) {
        tree = build(in, pre, 0, pre.size() - 1);
        preIndex = 0;
        postorder(tree);
        cout << '\n';
    }
    return 0;
}
