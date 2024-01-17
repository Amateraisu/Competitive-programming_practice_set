#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;

struct point {
    int x, y;

    void read() {
        cin >> x >> y;
    }

    bool operator == (point other) {
        if (x == other.x || y == other.y) {
            return true;
        }
        return false;
    }
};
void test() {
    point p1, p2, p3, p4;
    p1.read();
    p2.read();
    p3.read();
    p4.read();
    int res = 0;
    if (p1 == p3) {
        if (p1.x == p3.x) {
            res = abs(p1.y - p3.y) * abs(p2.x - p4.x);
        } else {
            res = abs(p1.x - p3.x) * abs(p2.y - p4.y);
        }
    } else if (p1 == p2) {
        if (p1.x == p2.x) {
            res = abs(p1.y - p2.y) * abs(p3.x - p4.x);
        } else {
            res = abs(p1.x - p2.x) * abs(p3.y - p4.y);
        }
    } else { // here is if p1 == p4
        if (p1.x == p4.x) {
            res = abs(p1.y - p4.y) * abs(p2.x - p3.x);
        } else {
            res = abs(p1.x - p4.x) * abs(p2.y - p3.y);
        }

    }
    cout << res << '\n';
}
int main() {
    cin >> t;
    while (t--) test();

}
