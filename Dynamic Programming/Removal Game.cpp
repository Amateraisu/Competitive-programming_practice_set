#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n , x;
vector<ll>nums;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0 ;i < n; i++) {
        dp[i][i] = nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    ll tot = 0;
    for (ll i: nums) tot += i;
    cout << (dp[0][n - 1] + tot)/2 << '\n';
    return 0;
}
