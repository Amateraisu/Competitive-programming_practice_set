#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void test() {
    ll n;
    cin >> n;
    ll cur = 1;
    ll res = 0;
    for (int i = 0; i < 64; ++i) {
        if (n & (1LL << i)) ++res;
    }
    set<ll>s;
    for (int i = 1; cur <= n; ++i) {
        cur *= 1LL * i;
        s.insert(cur);
    }
    vector<ll>bin(s.begin(), s.end());
    for (ll i = 0; i < (1 << bin.size()); ++i) {
        ll cur = 0;
        ll cost = 0;
        for (int j = 0; j < 64; ++j) {
            if (i & (1 << j)) {
                // include this number;
                cur += bin[j];
                ++cost;
            }
        }
        ll need = n - cur;

        for (int j = 0; j < 64; ++j) {
            if (need & (1 << j)) ++cost;
        }
        res = min(res, cost);
    }
    std::cout << res << '\n';
}
// else if current is missing a bit

int main() {
    int t;
    cin >> t;
    while (t--) test();
}

