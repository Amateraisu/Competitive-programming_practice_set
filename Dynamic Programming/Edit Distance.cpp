#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n = 5000;
ll m;
vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, 1e5));

int main() {

    string str1, str2;
    cin >> str1 >> str2;
    m = str1.size();
    n = str2.size();
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) dp[0][i] = dp[0][i - 1] + 1;
    for (int j = 1; j <= m; j++) dp[j][0] = dp[j - 1][0] + 1;
    for (int i = 1; i <= m ; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});

            }


        }
    }
    cout << dp[m][n] << '\n';

    return 0;
}