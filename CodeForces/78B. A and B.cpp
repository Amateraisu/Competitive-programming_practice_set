#include <bits/stdc++.h>
using namespace std;


void test() {
    int a, b;
    cin >> a >> b;
    int d = abs(a - b);
    if (d == 0) {
        std::cout << 0 << '\n';
        return;
    }
    auto ok = [](int r, int d) {
        if (r * (r + 1)/2 < d) return false;
        int t = r * (r + 1)/2;
        return t % 2 == d % 2;
    };

    int res = 1;
    while (!ok(res, d)) {
        ++res;
    }
    std::cout << res << '\n';


}

int main() {
    int t;
    cin >> t;
    while (t--) test();
}
