#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, q;
int a, b;
constexpr int maxN = 2e5 + 1;
int dp[maxN][32];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &dp[i][0]);
    }
    for (int i = 1; i < 32; i++) {
        for (int j = 0; j <= n - (1 << i); j++) {
            dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        int k = log2(b - a + 1);
        printf("%d\n", min(dp[a][k], dp[b - (1 << k) + 1][k]));
    }

    return 0;
}
