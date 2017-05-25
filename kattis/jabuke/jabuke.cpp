#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point(int _x, int _y) : x(_x), y(_y) {}
};

double area(point &p1, point &p2, point &p3) {
    return fabs((p1.x*(p2.y - p3.y)) + (p2.x*(p3.y - p1.y))
            + (p3.x*(p1.y - p2.y))) / 2;
}

bool is_inside(point &p, point &p1, point &p2, point &p3) {

    double A = area(p1, p2, p3);
    double A1 = area(p, p2, p3);
    double A2 = area(p1, p, p3);
    double A3 = area(p1, p2, p);

    return A == (A1 + A2 + A3);
}

int main() {
    int n, cont = 0;
    int x, y;

    cin >> x >> y;
    point p1(x, y);

    cin >> x >> y;
    point p2(x, y);

    cin >> x >> y;
    point p3(x, y);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        point p(x, y);
        if(is_inside(p, p1, p2, p3)) cont++;
    }
    printf("%.1f\n%d\n", area(p1, p2, p3), cont);

    return 0;
}
