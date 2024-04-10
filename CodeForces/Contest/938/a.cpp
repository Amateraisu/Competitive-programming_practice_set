#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a * 2 > b) {
        // use b
        ll c = n/2 * b;
        if (n % 2 != 0) c += a;
        cout << c << '\n';

    } else {
        // use a
        cout << 1LL * a * n << '\n';

    }
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
