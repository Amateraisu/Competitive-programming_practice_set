#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void test() {
    int n;
    cin >> n;
    vector<int>ret(n , 0);
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    int m = n/2;
    for (int i = 0; i < m; ++i) {
        ret[m + i] = nums[i];
    }
    for (int i = m; i < n; ++i) {
        ret[i] = nums[i - m];
    }
    for (int x : ret) {
        cout << x << '\n';
    }

}
constexpr int MOD = 1e9 + 7;

ll get(ll base, ll pow, ll m) {

    ll res = 1;
    base %= m;
    while (pow) {
        if (pow & 1) {
            res = res * base;
            res %= m;
        }
        base = base * base;
        base %= m;
        pow >>= 1;
    }

    return res;



}



int main() {
    int n;
    cin >> n;
    vector<ll>dp(n + 1, 0);
    for (int i = 1; i <= min(6, n); ++i) {
        dp[i] = 1LL;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] = dp[i] + dp[i - j];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n] << '\n';

}
