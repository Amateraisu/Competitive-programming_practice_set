#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int maxN = 20;
constexpr ll MOD = 1e9 + 7;

int n, m;
bool visited[1 << maxN][maxN];
ll dp[1 << maxN][maxN];
queue<pair<ll, ll>>q;



int main() {
    cin >> n >> m;
    map<int, vector<int>>g;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);

    }
    dp[1][0] = 1;
    q.push({1, 0});
    visited[1][0] = true;
    while (!q.empty()) {
        int mask = q.front().first;
        int u = q.front().second;
        q.pop();
        if (u != n - 1) {
            for (int v : g[u]) {
                ll newMask = mask | (1 << v);
                if ((mask & (1 << v)) == 0) {
                    dp[newMask][v] += dp[mask][u];
                    dp[newMask][v] %= MOD;
                    if (!visited[newMask][v]) {
                        visited[newMask][v] = true;
                        q.push({newMask, v});
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << '\n';
}