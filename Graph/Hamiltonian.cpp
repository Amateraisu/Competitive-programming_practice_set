#include <bits/stdc++.h>
constexpr int maxN = 20 + 1;
constexpr int MOD = 1e9 + 7;
using ll = long long;
using namespace std;

vector<int> g[maxN];
int dp[20][(1 << maxN) + 1];
int a, b, n , m;
int fin = 0;
ll dfs(int u =  0, int mask = 1) {
    if (dp[u][mask] != 0) {
        return dp[u][mask];
    }
    if (u == n - 1) {
        if (mask == fin) {
            return 1;
        }
        return 0;
    }
    ll cur = 0;
    for (int v : g[u]) {
        if (((1 << v) & mask) == 0) {
            int nMask = mask | (1 << v);
            cur += dfs(v, nMask);
            cur %= MOD;
        }
    }
    dp[u][mask] = cur;

    return cur;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a - 1].push_back(b - 1);
    }
    fin = (1 << n) - 1;
    ll res = dfs();

    cout << res << '\n';

    return 0;
}