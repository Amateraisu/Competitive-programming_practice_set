#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll t;

void test() {
    int n;
    string x , y;
    cin >> n;
    cin >> x;
    cin >> y;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
        if (x[i] != y[i]) {
            c1 += x[i] - '0';
            c2 += y[i] - '0';
        }
    }
    int res = min(c1, c2) + abs(c1 - c2);
    cout << res << '\n';
}

int main() {
    cin >> t;
    while (t--) test();
}
