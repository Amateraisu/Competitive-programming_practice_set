#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
int d;
int main() {
    
    cin >> n;
    vector<int>days(n, -1);
    vector<vector<int>>dp(n + 1, vector<int>(3, 0));
    for (int i = 0; i< n; ++i) cin >> days[i];
    // 0 = rest 
    // 1 = gym 
    // 2 = contest 
    // find the maximum number of days which he will not have a rest 
    for (int i = n - 1; i >= 0; --i) {
         if (days[i] == 1) {
            dp[i][2] = max(dp[i + 1][0], dp[i + 1][1]) + 1;
        } else if (days[i] == 2) {
            dp[i][1] = max(dp[i + 1][0], dp[i + 1][2]) + 1;
        } else if (days[i] == 3) {
            dp[i][2] = max(dp[i + 1][0], dp[i + 1][1]) + 1;
            dp[i][1] = max(dp[i + 1][0], dp[i + 1][2]) + 1;
        }
        dp[i][0] = max(dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = max(dp[i][0], dp[i + 1][2]);
    }
    int res = max(dp[0][0], dp[0][1]);
    res = max(res, dp[0][2]);
    
    cout << n - res << '\n';
    
    
    
    return 0;
}
