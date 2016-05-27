#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, b, cont = 0;

    cin >> n >> d >> b;

    vector<int> birds(b);

    for(int i = 0; i < b; i++)
        cin >> birds[i];

    sort(birds.begin(), birds.end());
    birds.insert(birds.begin(), 6);

    for(int i = 1; i < birds.size(); i++) {
        for(int j = birds[i] - d - 1; j >= birds[i - 1] -1; j -= d){
            cont++;
        }
    }

    for(int i = birds.back(); i < n - 5; i += d)
        cont++;

    cout << cont - birds.size() + 1 << '\n';
    return 0;
}
