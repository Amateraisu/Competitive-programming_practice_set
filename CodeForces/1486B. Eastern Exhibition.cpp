#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;

struct points {
    int x, y;

    void read() {
        cin >> x >> y;
    }
};
void test() {
    int n;
    cin >> n;
    vector<points>nums;
    for (int i = 0; i < n; ++i) {
        points p;
        p.read();
        nums.push_back(p);
    }
    vector<int>p1;
    vector<int>p2;
    for (auto& p : nums) {
        p1.push_back(p.x);
        p2.push_back(p.y);
    }
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    int x1, x2;
    if (p1.size() % 2 == 0) {
        x1 = p1[p1.size() / 2] - p1[p1.size()/2 - 1];
    } else {
        x1 = 1;
    }
    if (p2.size() % 2 == 0) {
        x2 = p2[p2.size() / 2] - p2[p2.size()/2 - 1];
    } else {
        x2 = 1;
    }
    cout << x1 *x2 << '\n';



}
int main() {
    cin >> t;
    while (t--) test();
}