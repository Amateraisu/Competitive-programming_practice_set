#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    ll n;
    cin >> n;
    std::array<ll, 65>dp;
    dp[0] = 0;
    ll cur = 0;
    for (int i = 1; i < 64; ++i) {
        ll cost =  (1 << (i - 1));
        cur += cost;
        dp[i] = cost;
    }
    ll ret = 0;
    for (int i = 63; i >= 0; --i) {
        if (n & 1LL * (1 << i)) {
            ret += dp[i];
        }
    }
    std::cout << ret << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) test();
}
