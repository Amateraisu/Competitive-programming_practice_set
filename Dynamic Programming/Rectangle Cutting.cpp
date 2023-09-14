#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;

ll a = 500, b = 500;



int solve(int r , int c) {
    vector<vector<int>>dp(r + 1, vector<int>(c + 1, 1e5));
    for (int row = 1; row <= r; row++) {
        for (int col = 1; col <= c; col++) {
            if (row == col) {
                dp[row][col] = 0;
            } else {
                int t = 1e5;
                for (int i = 1; i < row; i++) {
                    t = min(t, 1 + dp[row - i][col] + dp[i][col]);
                }
                for (int j = 1; j < col ; j++) {
                    t = min(t, 1 + dp[row][j] + dp[row][col - j]);
                }
                dp[row][col] = t;
            }

        }
    }
    return dp[r][c];

}
int main() {

    cin >> a >> b;
    int res = solve(a, b);
    cout << res << '\n';
    return 0;
}

