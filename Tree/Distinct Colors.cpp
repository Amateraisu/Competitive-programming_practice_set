#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxN = 2e5 + 1;

set<int>colors[maxN];
int res[maxN];
int col[maxN];
vector<int> g[maxN];
int a, b, n;
ll c;

void dfs(int u = 1, int p = -1) {
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            if (colors[v].size() > colors[u].size()) {
                swap(colors[u], colors[v]);
            }
            for (int e : colors[v]) {
                colors[u].insert(e);
            }
        }
    }
    res[u] = colors[u].size();
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &col[i]);
        colors[i].insert(col[i]);
    }
    for (int i = 0 ; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs();
    for (int i = 1; i <=n ; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}