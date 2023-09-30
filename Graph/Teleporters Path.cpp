#include <bits/stdc++.h>
using namespace std;
constexpr int maxN = 2e5 + 1;
constexpr int maxM = 2e5 + 1;
int a, b, n, m;
int IN[maxN];
vector<int> g[maxN];
bool vis[maxN];
vector<int>res;
stack<int>s;



void dfs1(int u = 1, int p = -1) {
    vis[u] = true;
    for (int v: g[u]) {
        if (v != p && !vis[v]) {
            dfs1(v, u);
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i<= m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        IN[b]++;
    }
    dfs1();
    bool exists = vis[n];
    exists &= (IN[1] + 1 == static_cast<int>(g[1].size()));
    exists &= (IN[n] - 1 == static_cast<int>(g[n].size()));
    for(int i = 2; i < n; i++){
        exists &= (IN[i] == (int) g[i].size());
        if(!vis[i]) exists &= (IN[i] == 0 && g[i].size() == 0);
    }
    if (!exists) {
        printf("IMPOSSIBLE\n");
        return 0;
    }

    s.push(1);
    while (!s.empty()) {
        int u = s.top();
        if (!g[u].empty()){
            int v = g[u].back();
            g[u].pop_back();
            s.push(v);
        } else {
            res.push_back(u);
            s.pop();
        }
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < m + 1 ; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
