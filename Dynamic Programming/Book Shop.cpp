#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;



int main() {
    int n, x;
    cin >> n >> x;
    vector<int>prices(n);
    vector<int>cnt(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> cnt[i];
    // let do a dfs first
    // this is a classic knapsack problem
    vector<vector<int>>dp(n + 1, vector<int>(x + 1 , 0)); // dp[i][j] represents the number of pages I can buy with i from pages till index j
//    dp[9][2] = 13
    // dp[i][j] = max(dp[i-price][j] + pageCount,
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x ;j++) {
            dp[i + 1][j] = dp[i][j];
            if (j >= prices[i]) {
                dp[i + 1][j] = max(dp[i + 1][j], cnt[i] + dp[i][j - prices[i]]);
            }
        }
    }
    cout << dp[n][x] << '\n';
}