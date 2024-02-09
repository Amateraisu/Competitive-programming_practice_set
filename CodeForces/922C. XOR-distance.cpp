#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void test() {
    ll a, b, x, c, d;
    cin >> c >> d >> x;
    ll res = 0;
    a = max(c, d);
    b = min(c, d);
    int start =- 1;
    for (int i = 63; i >= 0; --i) {
        int l = (a & (1LL << i));
        int r = (b & (1LL << i));
        if (l != r) {
            // favour a here
            // dont need to set a bit
            start = i;
        }
    }
    for (int i = start - 1; i >= 0; --i) {
        int l = (a & (1LL << i));
        int r = (b & (1LL << i));
        if (l != r && l == 1) {
            // set it to 1
            if (res + (1LL << i) <= x) res |= (1LL << i);

        } else if (l != r && r == 1) {
            // dont need to set it
            continue;
        }
    }
    std::cout << abs((a ^ res) - (b ^ res)) << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) test();
}
