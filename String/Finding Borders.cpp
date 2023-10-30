#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
constexpr int MOD = 1e9 + 7;

int main() {

    cin >> s;
    int n = s.size();
    vector<ll>dp(n, 0);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i] = static_cast<ll>(s[i]);
        } else {
            dp[i] = ((dp[i - 1] * 26) + static_cast<ll>(s[i])) % MOD;
        }
    }
    ll P = 1;
    for (int i = 1; i < n; i++) {
        P = (P*26) % MOD;
        ll suf = (dp[n - 1] - (dp[n - 1 - i] * P) % MOD + MOD) % MOD;
        if (dp[i - 1] == suf) {
            printf("%d ", i);
        }
    }
    return 0;
}
