#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;

ll exp(ll a, ll b, ll mod) {
    // use fermet's
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void test() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = exp(b, c, MOD - 1);
    ll res = exp(a, x, MOD);
    std::cout << res << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) test();
}