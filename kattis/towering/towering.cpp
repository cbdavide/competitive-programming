#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi alocate(int *values, vb &flags, bool cond) {
    vi arr;
    for(int i=0; i<flags.size(); i++) {
        if(flags[i] == cond)
            arr.push_back(values[i]);
    }
    sort(arr.rbegin(), arr.rend());
    return arr;
}

int main() {
    int *arr, a, b;
    arr = new int[6];
    vector<bool> res(6, 0);
    for(int i=0; i<6; i++) cin >> arr[i];
    cin >> a >> b;

    for(int i=0; i<6; i++) {
        for(int j=i+1; j<6; j++) {
            for(int k=j+1; k<6; k++) {
                int anws = arr[i] + arr[j] + arr[k];
                if(anws == a){
                    res[i] = res[j] = res[k] = 1;
                }
            }
        }
    }

    vi aa = alocate(arr, res, 1);
    vi bb = alocate(arr, res, 0);
    for(int i=0; i<aa.size(); i++)
        cout << aa[i] << ' ';
    for(int i=0; i<bb.size(); i++) {
        cout << bb[i];
        if(i < 2) cout << ' ';
    }
    cout << '\n';
    return 0;
}
