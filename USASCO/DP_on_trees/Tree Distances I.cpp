#include <bits/stdc++.h>
using namespace std;

constexpr int maxN = 2e5 + 1;
int dp[maxN], dp2[maxN];
vector<int> G[maxN];


void dfs(int u, int p) {
    for (int v : G[u]) {
        if (v != p) {
            dp[v] = dp[u] + 1;
            dfs(v, u);
        }
    }
}

void dfs2(int u, int p) {
    for (int v : G[u]) {
        if (v != p) {
            dp2[v] = dp2[u] + 1;
            dfs2(v, u);
        }
    }
}


int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, -1);
    int a;
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] > c) {
            a = i;
            c = dp[i];
        }
    }
    dp2[a] = 0;
    dfs2(a, -1);
    c = 0;
    int b;
    for (int i = 1; i <= n; ++i) {
        if (dp2[i] > c) {
            c = dp2[i];
            b = i;
        }
    }
    dp[b] = 0;
    dfs(b, -1);
    for (int i = 1; i <= n;++i) {
        cout << max(dp[i] , dp2[i]) << ' ';
    }






}