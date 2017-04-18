#include <bits/stdc++.h>
using namespace std;

bool h(int a, int b) {
  return (a == 1 && b == 2) || (a == 2 && b == 1);
}

bool du(int a, int b) {
  return a == b;
}

int main() {
  int a, b, c, d, cond = 0;
  while(cin >> a >> b >> c >> d && (a + b + c +d)) {
    if(h(a, b) && h(c, d)) cond = 0;
    else if(h(a, b)) cond = 1;
    else if(h(c, d)) cond = 2;
    else if(du(a, b) && du(c, d)) {
      cond = a > c ? 1 : 2;
      cond = a == c ? 0 : cond;
    }else if(du(a, b)) {
      cond = 1;
    }else if(du(c, d)) {
      cond = 2;
    }else {
      if(a < b) swap(a, b);
      if(c < d) swap(c, d);
      if(a == c && b == d) cond = 0;
      else if((a * 10 + b) > (c * 10 + d))
        cond = 1;
      else
        cond = 2;
    }
    if(cond)
      printf("Player %d wins.\n", cond);
      else printf("Tie.\n");
  }
  return 0;
}
