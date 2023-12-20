#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
constexpr int INF = 0x3f3f3f3f;
int main() {
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    vector<vector<int>>dp(n + 1, vector<int>(n + 1, -INF));
    for (int i = 0; i <= n; ++i) dp[i][0] = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (dp[i - 1][j - 1] + nums[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j - 1] + nums[i - 1], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = n; i >= 0; i--)
    {
        if (dp[n][i] >= 0)
        {
            cout << i;
            return 0;
        }
    }
//    cout << res << '\n';



    return 0;
}
