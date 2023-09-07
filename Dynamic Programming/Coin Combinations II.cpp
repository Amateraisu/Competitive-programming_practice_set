#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;

int n, x;

int main() {
    cin >> n >> x;
    int MOD = 1e9 + 7;
    vector<int>coins(n, 0);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<vector<ll>> dp(x + 1, vector<ll>(n, 0)); // dp[i][j] represents the amount of ways to make amount i at the jth index
    for (auto c : coins) dp[c][]
    return 0;
}
