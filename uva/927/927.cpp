#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int t, n, *an, d, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        an = new int[n + 1];
        for(int i=0; i<=n; i++) scanf("%d", &an[i]);
        scanf("%d %d", &d, &k);

        int j = 0;
        long long sn = 0;
        while (sn < k) {
            sn = sn + (long long)((++j) * d);
        }

        long long answ = 0;
        for(int i=0; i<=n; i++) {
            answ += (long long)an[i] * (long long)pow(j, i);
        }

        printf("%lld\n", answ);
    }
    return 0;
}
