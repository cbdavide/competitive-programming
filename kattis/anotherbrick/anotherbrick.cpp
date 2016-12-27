#include <iostream>
#include <queue>

using namespace std;

bool fill_w(int w, queue<int> &cola) {
    int cont = 0;
    while(cont < w && !cola.empty()) {
        cont += cola.front();
        cola.pop();
    }

    return cont == w;
}

bool fill_h(int h, int w, queue<int> cola) {
    int i;
    for(i=0; i<h; i++) {
        if(!fill_w(w, cola))
            return false;
    }
    return i == h;
}

int main() {
    int h, w, n, t;
    queue<int> cola;

    cin >> h >> w >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        cola.push(t);
    }

    if(fill_h(h, w, cola))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
