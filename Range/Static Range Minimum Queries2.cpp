#include <bits/stdc++.h>
using namespace std;
constexpr int maxN = 2e5 + 1;
constexpr int bits = 32;
int n, q, a, b, x;
constexpr int INF = 0x3f3f3f3f;

int main() {
    scanf("%d %d", &n, &q);
    int dp[maxN][32];
    vector<int>arr(n, 0);
    for (int i = 0; i < n ; i++) {
        scanf("%d", &arr[i]);
        dp[i][0] = arr[i];
    }
    for (int i = 1; i < bits; i++) {
        for (int j = 0; j <= n - (1 << i); j++) {
            dp[j][i] = min(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        int bit = log2(b - a + 1);
        printf("%d\n", min(dp[a][bit], dp[b - (1 << bit) + 1][bit]));
    }

    return 0;
}
