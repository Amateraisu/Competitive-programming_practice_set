#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>values(n);
    for (int i  = 0; i < n; i++) cin >> values[i];
    vector<vector<ll>>dp(n, vector<ll>(m + 1, 0));
    if (values[0] != 0) {
        dp[0][values[0]] = 1;
    } else {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }
    int MOD = 1e9 + 7;
    for (int i = 1; i < n; i++) {
        if (values[i] == 0) {
            for (int j = 1; j <= m ; j++) {
                dp[i][j] = dp[i - 1][j] % MOD;
                if (j - 1 > 0) dp[i][j] += dp[i - 1][j - 1] % MOD, dp[i][j] %= MOD;
                if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1] % MOD, dp[i][j] %= MOD;
            }
        } else {
            dp[i][values[i]] = dp[i - 1][values[i]] % MOD;
            if (values[i] - 1 >0) dp[i][values[i]] += dp[i - 1][values[i] - 1] % MOD, dp[i][values[i]] %= MOD;
            if (values[i] + 1 <= m) dp[i][values[i]] += dp[i - 1][values[i] + 1] % MOD, dp[i][values[i]] %= MOD;
        }
    }
    ll res = 0;
    for (int i = 1 ; i <= m ; i++) {
        res += dp[n - 1][i] % MOD;
        res %= MOD;
    }
    cout << res << '\n';
    return 0;
}