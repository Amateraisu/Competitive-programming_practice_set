#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxN = 2e5 + 1;
int n, m;
int a, b;
int vis[maxN];

int par[maxN];
vector<int> g[maxN];
using edge = tuple<int, int>;
queue<edge>q;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
    vis[1] = 1;
    q.push({1, 1});
    while (!q.empty()) {
        edge s = q.front();q.pop();
        int u = get<0>(s);
        int cost = get<1>(s);
        if (u == n) {
            printf("%d\n", cost);
            break;
        }
        for (int v: g[u]) {
            if (vis[v] == 0) {
                vis[v] = 1;
                par[v] = u;
                q.push({v, cost + 1});
            }
        }
    }
    if (!vis[n]) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    vector<int>res;
    int ptr = n;
    while (ptr != par[ptr]) {
        res.push_back(ptr);
        ptr = par[ptr];
    }
    res.push_back(ptr);
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }

    return 0;

}
