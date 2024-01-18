#include <bits/stdc++.h>
using namespace std;

struct point {
    int a, b, c, d, e;
    int key = 0;
    void read() {
        cin >> a >> b >> c >> d >> e;
    }
    bool operator > (point& o) {
        int c1 =0;
        if (a > o.a) ++c1;
        if (b > o.b) ++c1;
        if (c > o.c) ++c1;
        if (d > o.d) ++c1;
        if (e > o.e) ++c1;
        return c1 < 3;
    }
};

void test() {
        int n;
    cin >> n;
    vector<point>points;
    for (int i = 0; i < n; ++i) {
        point p;
        p.key = i + 1;
        p.read();
        points.push_back(p);
    }
    auto c = [](point& a, point& b) {
        int c1 =0;
        if (a.a > b.a) ++c1;
        if (a.b > b.b) ++c1;
        if (a.c > b.c) ++c1;
        if (a.d > b.d) ++c1;
        if (a.e > b.e) ++c1;
        return c1 < 3;
    };
    sort(points.begin(), points.end(), c);
    // for (int i = 0; i < n; ++i) {
    //     cout << points[i].key << '\n';
    // }
    // cout << "Initial candidate " << points[0].key << '\n';
    // go through the rest of the points and see.
    for (int i = 1; i < points.size(); ++i) {
        if (points[i] > points[0]) {
            // cout << "Error occured at candidate " << points[i].key << '\n';
            cout << -1 << '\n';
            return;
        }
    }
    cout << points[0].key << '\n';

}
int t;

int main() {
    cin >> t;
    while (t--) test();

    return 0;

}