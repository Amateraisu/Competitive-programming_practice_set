#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;

int main() {
    cin >> n;
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    map<ll, ll>mp;
    for (ll x: nums) mp[x] += x;
    vector<ll>nums2;
    for (auto& [a, b]: mp) {
        nums2.push_back(a);
    }
    vector<ll>dp(nums2.size(), 0);
    ll res = 0;
    for (int i = 0 ; i < nums2.size(); ++i) {
        // at this index I can choose to take it or dont take it
        // if I take it
        dp[i] = mp[nums2[i]];
        if (i > 0 && nums2[i - 1] + 1 != nums2[i]) {
            dp[i] = max(dp[i - 1] + mp[nums2[i]], dp[i]);
        }
        // then what about the 2 indexes prior to this?
        if (i >= 2) {
            dp[i] = max(dp[i - 2] + mp[nums2[i]], dp[i]);
        }
        if (i > 0) dp[i] = max(dp[i], dp[i - 1]);

    }
    cout << dp[dp.size() - 1] << '\n';

}
