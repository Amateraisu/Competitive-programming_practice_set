#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;

void test() {
    int x, n;
    cin >> x >> n;
    int res = 1;
    for (int i = 1 ; i * i <= x ; ++i) {
        if (x % i == 0) {
            int d1 = i;
            int d2 = x / i;
            if (n <= x/i) res = max(res, i);
            if (n <= i) res = max(res, x/i);
        }
    }
    std::cout << res << '\n';

}
int main() {
    cin >> t;
    while (t--) test();
}