#include <bits/stdc++.h>
using namespace std;
using ll = long long;


constexpr ll MOD = 1e9 + 7;


void test() {
    ll a, b;
    cin >> a >> b;
    ll cur = 1;
    while (b > 0) {
        if (b & 1) {
            cur = ((cur % MOD) * (a % MOD)) % MOD;
        }
        a = ((a % MOD) * (a % MOD)) % MOD;
        b >>= 1;
    }
    cout << cur << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) test();
}