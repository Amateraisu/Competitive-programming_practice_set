#include <bits/stdc++.h>
using namespace std;

constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;
int a, b, n, m;
int vis[maxN];
vector<int> g[maxN];
int IN[maxN];
stack<int> s;
vector<int> res;
void dfs(int u = 1, int p = -1) {
    vis[u] = 1;
    for (int v: g[u]) {
        if (!vis[v] && v != p) {
            dfs(v, u);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        IN[b]++;
    }
    dfs();
    if (!vis[n]) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    bool exist = true;
    exist &= (IN[1] + 1 == static_cast<int>(g[1].size()));
    exist &= (IN[n] - 1 == static_cast<int>(g[n].size()));
    for (int i = 2; i < n ; i++) {
        exist &= (IN[i] == (int) g[i].size());
        if (!vis[i]) exist &= (IN[i] == 0 && g[i].size() == 0);
    }
    if (!exist) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    s.push(1);
    while (!s.empty()) {
        int u = s.top();
        if (!g[u].empty()) {
            int v = g[u].back();
            g[u].pop_back();
            s.push(v);
        } else {
            s.pop();
            res.push_back(u);
        }
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < m + 1; i++) {
        printf("%d ", res[i]);
    }



    return 0;
}
