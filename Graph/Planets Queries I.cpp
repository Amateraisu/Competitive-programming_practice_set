#include <bits/stdc++.h>
using ll = long long;
constexpr int maxN = 2e5 + 1;
using namespace std;
int q;
constexpr int bits = 31;
int dp[maxN][bits];
int n, a, b;

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dp[i][0]);
    }
    for (int j = 1; j < bits; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);

        for (int j = 0; j < bits; j++) {
            if (b & (1 << j)) {
                a = dp[a][j];
            }
        }
        cout << a << '\n';

    }
    return 0;
}