#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxN = 2e5 + 1;
int n, q;
ll a, b;
constexpr int bits = 32;
int dp[maxN][bits];
int main() {
    scanf("%d %d", &n, &q);
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <=n ; i++) {
        scanf("%d" , &dp[i][0]);
    }
    for (int j = 1; j < bits; j++) {
        for (int i = 2; i <=n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &a, &b);
        for (int j = bits - 1; j >=0 ; j--) {
            if (b & (1 << j)) {
                a = dp[a][j];
            }
        }
        printf("%lld\n", a ? a : -1);
    }
    return 0;
}
