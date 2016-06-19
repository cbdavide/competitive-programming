#include <bits/stdc++.h>
using namespace std;

struct segtree {

  int from, to, value;
  segtree *left, *right;

  segtree(int l, int r){
    from = l;
    to = r;
    value = 0;
    left = right = NULL;
  }
};

segtree* build(int l, int r){

  if(l > r)
    return NULL;

  segtree *answ = new segtree(l, r);

  if(l == r){
    answ -> value = 0;
  } else {
    int m = (l + r) / 2;

    answ -> left = build(l, m);
    answ -> right = build(m + 1, r);

    if(answ -> left != NULL)
      answ -> value += answ -> left -> value;
    if(answ -> right != NULL)
      answ -> value += answ -> right -> value;
  }
  return answ;
}

int query(segtree *tree, int l, int r) {

  if(tree == 0)
    return 0;
  if(l <= tree -> from && tree -> to <= r)
    return tree -> value;
  if(tree -> to < l)
    return 0;
  if(r < tree -> from)
    return 0;

  return query(tree -> left, l, r) + query(tree -> right, l, r);
}

int update(segtree *tree, int i, int val) {
  if(tree == NULL)
    return 0;
  if(tree -> to < i)
    return tree -> value;
  if(i < tree -> from)
    return tree -> value;

  if(tree -> from == tree -> to && tree -> from == i)
    tree -> value = val;
  else
    tree -> value = update(tree -> left, i, val) + update(tree -> right, i, val);

  return tree -> value;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int size, q, a, b, val;
  char op;

  cin >> size >> q;

  segtree *tree = build(0, size - 1);

  for(int i=0; i<q; i++) {
    cin >> op;

    if(op == 'F') {
      cin >> a;

      val = query(tree, a - 1, a - 1);

      if(val)
	update(tree, a - 1, 0);
      else
	update(tree, a - 1, 1);      

    } else {
      cin >> a >> b;
      cout << query(tree, a - 1, b - 1) << '\n';
    } 

  }

  return 0;
}
