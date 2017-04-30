#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vi::iterator vitr;

int main() {
    int n, t, diff, *arr, a, b, temp;
    vitr comp;

    while(cin >> n) {
        vi arr(n);

        for(int i=0; i<n; i++) cin >> arr[i];
        cin >> t;

        diff = 1e8;
        sort(arr.begin(), arr.end());
        for(vitr i=arr.begin(); i!=arr.end(); i++) {
            temp = t - *i;
            comp = lower_bound(arr.begin(), arr.end(), temp);
            if(*comp != temp || comp == i || comp == arr.end())
                continue;
            if(abs(temp - *i) < diff) {
                diff = temp - *i;
                a = *i;
                b = temp;
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }
    return 0;
}
