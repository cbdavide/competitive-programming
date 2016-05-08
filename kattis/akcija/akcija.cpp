#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

main() {
    int n, total = 0;

    cin >> n;

    vector<int> books(n);

    for(int i=0; i<n; i++)
        cin >> books[i];

    sort(books.rbegin(), books.rend());

    for(int i=0; i<books.size(); i++) {
        if((i+1) % 3 != 0)
            total += books[i];
    }
    cout << total << '\n';
}
