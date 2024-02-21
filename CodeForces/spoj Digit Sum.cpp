#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[100][2];

void reset() {
    for (int i = 0; i < 100; ++i) {
        dp[i][0] = -1;
        dp[i][1] = -1;

    }
}

ll dfs(ll limit, int i = 0, bool z = false) {
    if (i == to_string(limit).size()) return 0;
    if (dp[i][z] != -1) {
        return dp[i][z];
    }
    dp[i][z] = 0;
    int ub = -1;
    if (!z) ub = to_string(limit)[i] - '0';

    if (z) {
        // pick any number here
        for (int i = 0; i < 9; ++i) {
            dp[i][z] += dfs(limit, i + 1, true) + i;
        }
    } else {

        // pick a restrained
        for (int i = 0; i < ub - 1; ++i) {
            dp[i][z] += dfs(limit, i + 1, true) + i;
        }
        dp[i][z] +=dfs(limit, i + 1, false) + ub;

    }

    return dp[i][z];

}




void test() {
    ll a, b;
    cin >> a >> b;
    ll total = dfs(b);
    cout << total - dfs(a - 1) << '\n';

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        reset();
        test();
    }
}
