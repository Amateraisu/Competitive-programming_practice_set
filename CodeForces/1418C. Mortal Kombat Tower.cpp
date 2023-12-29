#include <bits/stdc++.h>
using namespace std;

int t;
constexpr int INF = 0x3f3f3f3f;

int dfs(int index, int turn , vector<int>& nums, vector<vector<int>>& dp) {
    if (index >= nums.size()) return 0;
    if (dp[index][turn] != -1) return dp[index][turn];
    int n = nums.size();
    int res = INF;
    int temp = INF;
    if (turn == 1) {
        if (nums[index] == 1) temp = min(temp, dfs(index + 1, 0, nums, dp) + 1);
        if (nums[index] == 0) temp = min(temp, dfs(index + 1, 0, nums, dp));
        if (index + 1 < n && nums[index] == 0 && nums[index + 1] == 1) temp = min(temp, dfs(index + 2, 0, nums, dp) + 1);
        if (index + 1 < n && nums[index] == 0 && nums[index + 1] == 0) temp = min(temp, dfs(index + 2, 0, nums, dp));
        if (index + 1 < n && nums[index] == 1 && nums[index + 1] == 0) temp = min(temp, dfs(index + 2, 0, nums, dp) + 1);
        if (index + 1 < n && nums[index] == 1 && nums[index + 1] == 1) temp = min(temp, dfs(index + 2, 0, nums, dp) + 2);

        res = min(temp, res);


    } else {
        temp = min(dfs(index + 1, 1, nums, dp), dfs(index + 2, 1, nums, dp));
        res = min(res, temp);

    }


    dp[index][turn] = res;
    return res;
}


void test() {
    int n;
    cin >> n;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    vector<vector<int>>dp(n + 1, vector<int>(2, -1));
    int res = dfs(0, 1, nums, dp);
//     dp[0][n] = dp[1][n] = 0;
//     for (int i = n - 1; i >= 0; --i) {
//         // settle friend first
//         // can always settle 1 state ahead
//         dp[0][i] = min(dp[0][i], dp[1][i + 1]);
//         if (i + 2 <= n) {
//             dp[0][i] = min(dp[0][i], dp[1][i + 2]);
//         }
//         dp[1][i] = min(dp[1][i], dp[0][i + 1]);
//         if (i + 2 <= n) {
//             dp[1][i] = min(dp[1][i], dp[0][i + 2]);
//         }
//         if (nums[i] == 1) ++dp[1][i];


//     }
//     cout << dp[1][0] << '\n';
    cout << res << '\n';

}

int main() {
    cin >> t;
    while (t--) test();
}
