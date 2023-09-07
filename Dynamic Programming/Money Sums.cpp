#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n;
set<ll> res;
int main() {
    cin >> n;
    ll total = 0;
    vector<ll>nums(n, 0);
    for (int i = 0; i < n; i++) cin >> nums[i], total += nums[i];
    vector<vector<ll>>dp(n, vector<ll>(total + 1, 0));
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    dp[0][nums[0]] = 1;
    res.insert(nums[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= total; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - nums[i] >= 0) {
                dp[i][j] |= dp[i - 1][j- nums[i]];

            }
            if (dp[i][j] == 1) res.insert(j);
        }
    }
    cout << res.size() << '\n';
    for (auto x : res) cout << x << ' ';


    return 0;
}
