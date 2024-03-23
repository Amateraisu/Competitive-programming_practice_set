#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1e9 + 7;
void test() {
    int n, k;
    cin >> n >> k;
    vector<int>A(n, 0);
    for (int i = 0; i < n; ++i) cin >> A[i];
    ll cur = 0;
    ll maxi = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cur += A[i];
        sum += A[i];
        sum %= MOD;
        if (cur < 0) cur = 0;
        maxi = max(maxi, cur);
    }
    ll addition = 0;
    for (int i = 0; i < k;  ++i) {
        sum = ((sum % MOD) + (maxi % MOD)) % MOD;
        maxi = ((maxi % MOD) + (maxi % MOD)) % MOD;


    }
    cout << sum << '\n';
}

int main() {
    int n;
    cin >> n;
    while (n--) test();
}
