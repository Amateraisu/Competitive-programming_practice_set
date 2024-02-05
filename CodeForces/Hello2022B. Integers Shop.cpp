#include <bits/stdc++.h>
using namespace std;
struct p {
    int l;
    int r;
    int c;
};
constexpr int INF = 1e9 + 1;

void test() {
    int n;
    cin >> n;
    int res;
    int minL = INF, costL = INF;
    int maxR = 0, costR = INF;
    int maxLength = 0, cost = INF;
    int a, b, c;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        // extend the ranges
        if (a < minL) {
            minL = a;
            costL = INF;
        }
        if (a == minL) {
            costL = min(costL, c);
        }
        if (b > maxR) {
            maxR = b;
            costR = INF;
        }
        if (b == maxR) {
            costR = min(costR, c);
        }
        // but what if the new range contains the current range ?
        if (maxLength < b - a + 1) {
            maxLength = b - a + 1;
            cost = INF;
        }
        if (maxLength == b - a + 1) {
            cost = min(cost, c);
        }
        res = costL + costR;
        if (maxR - minL + 1 == maxLength) {
            res = min(res, cost);
        }
        std:: cout << res << '\n';

    }
}

int main() {
    int t;
    cin >> t;
    while (t--) test();
}