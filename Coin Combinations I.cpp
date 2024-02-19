#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = 1e9 + 7;
int main() {
    int n, k;
    cin >> n >> k;
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];

    }
    vector<int>dp(k + 1, 0);
    dp[0] = 1LL;
    for (int i = 1; i <= k; ++i) {
        for (auto c : nums) {
            if (i - c >= 0) {
                dp[i] += dp[i - c];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[k] << '\n';


}

