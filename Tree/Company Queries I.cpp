#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n, q, a, b;


int main() {
    cin >> n >> q;

    int bits = 32;
    vector<vector<int>> dp(n + 1, vector<int>(32, 0));
    for (int i = 2 ; i <= n; i++) {
        cin >> dp[i][0];
    }
    for (int j = 1; j < bits; j++) {
        for (int i = 2; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];

        }
    }
    for (int i = 0 ; i < q; i++) {
        cin >> a >> b;
        for (int j = 0 ; j < bits; j++) {
            if (b&(1 << j)) {
                a = dp[a][j];
            }
        }
        cout << (a ? a : -1) << '\n';
    }

    return 0;
}
