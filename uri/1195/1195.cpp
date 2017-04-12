#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct node {
    int val;
    node *left, *right;
    node(int _val) : val(_val), left(NULL), right(NULL) {};
};

node* insert(node *T, int val) {
    if(T == NULL) return new node(val);
    if(val < T->val) T->left = insert(T->left, val);
    else T->right = insert(T->right, val);
    return T;
}

void preorder(vi &arr, node *T) {
    if(T == NULL) return;
    arr.push_back(T->val);
    preorder(arr, T->left);
    preorder(arr, T->right);
}

void inorder(vi &arr, node *T) {
    if(T == NULL) return;
    inorder(arr, T->left);
    arr.push_back(T->val);
    inorder(arr, T->right);
}

void postorder(vi &arr, node *T) {
    if(T == NULL) return;
    postorder(arr, T->left);
    postorder(arr, T->right);
    arr.push_back(T->val);
}

void printa(vi &arr) {
    for(int i=0; i<arr.size(); i++) {
        printf("%d", arr[i]);

        if(i < arr.size() - 1)
            printf(" ");
    }
    printf("\n");
}

int main() {
    int t, v, a;
    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> v;
        node *tree = NULL;
        for(int j=0; j<v; j++) {
            cin >> a;
            tree = insert(tree, a);
        }
        vi pre, in, pos;
        preorder(pre, tree);
        inorder(in, tree);
        postorder(pos, tree);

        printf("Case %d:\n", i);
        printf("Pre.: ");
        printa(pre);
        printf("In..: ");
        printa(in);
        printf("Post: ");
        printa(pos);
        printf("\n");
    }
    return 0;
}
