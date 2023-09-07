#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n;
int main() {
    cin >> n;
    vector<ll>dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        int t = i;
        while (t > 0) {
            if (t % 10 != 0 && t - (t % 10) >= 0) {
                dp[i] = min(dp[i], dp[i - (t % 10)] + 1);
            }
            t /= 10;
        }
    }
    cout << dp[n] << '\n';

    return 0;
}
