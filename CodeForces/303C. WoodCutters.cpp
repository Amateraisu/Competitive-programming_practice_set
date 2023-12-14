#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, a, b;
int main() {
    cin >> n;
    vector<pair<ll, ll>>t(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        t[i] = make_pair(a, b);
    }
    vector<vector<ll>>dp(n, vector<ll>(3, 0));
    dp[0][1] = 1;
    if ((n > 1 && t[1].first - t[0].first >t[0].second) || (n == 1)) dp[0][2] = 1;
    for (int i = 1; i < n; ++i) {
        vector<ll>base = {dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]};
        dp[i][0] = *max_element(base.begin(), base.end()); // dont cut anything
        // if i lean to the left, can try previous standing or previous turn left
        if (t[i].first - t[i - 1].first > t[i].second) {
            // that means I can cut down this tree
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]);
            // what if I try to take the previous right side one ?
            if ((t[i - 1].second + t[i].second) < (t[i].first - t[i - 1].first)) {
                dp[i][1] = max(dp[i][1], dp[i- 1][2]);
            }
            ++dp[i][1];
        }
        // try and lean to the right
        if (i == n - 1 || (t[i + 1].first - t[i].first > t[i].second)) {
            // can cut down to the right side
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][2] = max(dp[i - 1][2], dp[i][2]);
            ++dp[i][2];

        }

    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            res = max(res, dp[i][j]);
        }
    }
    cout << res << '\n';
    return 0;
}