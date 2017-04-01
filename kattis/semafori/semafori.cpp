#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n, l, t = 0, pos = 0, aux;
    int d, r, g;

    scanf("%d %d", &n, &l);

    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &d, &r, &g);
        t += d - pos;
        pos = d;

        int wait = t % (r + g);
        if(wait < r)
            t += r - wait;
    }

    t += l - pos;

    printf("%d\n", t);
    return 0;
}
