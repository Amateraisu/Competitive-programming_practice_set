#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
int main() {
    cin >> n;
    vector<vector<ll>>dp(n, vector<ll>(3, 0));
    vector<ll>nums1(n, 0), nums2(n, 0);
    for (int i = 0; i < n ; ++i) cin >> nums1[i];
    for (int i = 0; i< n; ++i) cin >> nums2[i];
    dp[0][0] = nums1[0], dp[0][1] = nums2[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1] , dp[i - 1][2]) + nums1[i];
        dp[i][1] = max(dp[i - 1][0] , dp[i - 1][2]) + nums2[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]);
        dp[i][2] = max(dp[i][2] , dp[i - 1][0]);
    }
    ll res = max(dp[n - 1][0], dp[n - 1][1]);
    res = max(res, dp[n - 1][2]);

    cout << res << '\n';



    return 0;
}
