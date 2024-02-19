#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 0x3f3f3f3f;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];

    }
    vector<int>dp(k + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= k; ++i) {
        for (auto c : nums) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    cout << ((dp[k] == INF) ? -1 : dp[k])<< '\n';


}