#include <bits/stdc++.h>
using namespace std;
constexpr int maxN = 500 + 1;
using ll = long long;
ll dp[maxN][maxN];

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, q;
ll a, b, c;

int main() {
    for (int i = 0; i < maxN; i++) {
        for (int j = 0; j < maxN; j++) dp[i][j] = INF;
    }
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[a][b], c);
    }
    for (int i = 1; i<= n; i++) dp[i][i] =0;
    for (int k = 1; k <=n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", dp[a][b] >= INF ? -1 : dp[a][b]);
    }


    return 0;
}