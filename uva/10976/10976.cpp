#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

#define ll long long

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
    int k;
    ll x, y;
    while(scanf("%d", &k) > 0) {
        vpii values;
        for(int y = k + 1; y <= 2*k; y++) {
            if((y * k) % (y - k) == 0) {
                values.push_back(pii((y*k) / (y - k), y));
            }
        }
        printf("%d\n", values.size());
        for(int i=0; i<values.size(); i++) {
            printf("1/%d = 1/%lld + 1/%lld\n", k, values[i].first, values[i].second);
        }
    }
    return 0;
}
