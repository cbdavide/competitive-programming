#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
    point(int _x, int _y) : x(_x), y(_y) {}
};

int dir(point &p1, point &p2, point &p3) {
    point a(p3.x - p1.x, p3.y - p1.y);
    point b(p2.x - p1.x, p2.y - p1.y);
    return (a.x * b.y) - (a.y * b.x);
}

bool onsegment(point &a, point &b, point &c) {
    return (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) &&
        c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y));
}

bool intersect(point &p1, point &p2, point &p3, point &p4) {
    int d1 = dir(p3, p4, p1);
    int d2 = dir(p3, p4, p2);

    int d3 = dir(p1, p2, p3);
    int d4 = dir(p1, p2, p4);

    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;

    if(d1 == 0 && onsegment(p3, p4, p1)) return true;
    if(d2 == 0 && onsegment(p3, p4, p2)) return true;
    if(d3 == 0 && onsegment(p1, p2, p3)) return true;
    if(d4 == 0 && onsegment(p1, p2, p4)) return true;

    return false;
}

int main() {
    int t;
    int xs, xe, ys, ye, xleft, ytop, xright, ybottom;
    cin >> t;
    while(t--) {
        cin >> xs >> ys >> xe >> ye;
        cin >> xleft >> ytop >> xright >> ybottom;

        point p1(xs, ys), p2(xe, ye);

        point p3(xleft, ytop), p4(xleft, ybottom);
        point p5(xright, ytop), p6(xright, ybottom);

        bool cond = false;
        //Test if the segment is completely inside the rectangle.
        cond |= (onsegment(p3, p6, p1) && onsegment(p3, p6, p2));
        cond |= intersect(p1, p2, p3, p4);
        cond |= intersect(p1, p2, p5, p6);
        cond |= intersect(p1, p2, p3, p5);
        cond |= intersect(p1, p2, p4, p6);

        if(cond) cout << "T\n";
        else cout << "F\n";
    }
    return 0;
}
