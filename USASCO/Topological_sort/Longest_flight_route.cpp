// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;

int dp[maxN];
// this keeps track of the maximum number of flights there are
int p[maxN];
int IN[maxN];


int main() {
    int n, m;
    cin >> n >> m;
    memset(dp, 0, sizeof(int));
    memset(IN, 0, sizeof(int));
    memset(p, 0,sizeof(int));

    map<int, vector<int>>g;
    for (int i = 0; i < m ;++i) {
        // here is the prerequisites
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        ++IN[b];
    }
    queue<int>q;
    for (int i = 1; i <= n; ++i) {
        if (IN[i] == 0) q.push(i);
    }
    dp[1] = 1;

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dp[u] && dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                p[v] = u;
            }
            --IN[v];
            if (IN[v] == 0) {
                q.push(v);
            }
        }
    }
    if (p[n] == 0 || g[1].size() == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int>res;
        int ptr = n;
        while (p[ptr] != 0) {
            res.push_back(ptr);
            ptr = p[ptr];
        }
        cout << res.size() + 1 << '\n';
        cout << 1 << ' ';
        reverse(res.begin(), res.end());
        for (int x : res) {
            cout << x << ' ';
        }
        cout << '\n';

    }

    return 0;
}