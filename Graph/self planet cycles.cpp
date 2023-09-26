#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxN = 2e5 + 1;
vector<int> g[maxN];
int p[maxN];
int res[maxN];
int n;
int IN[maxN];
queue<int>q;
int vis[maxN];


void dfs1(int u) {
    for (int v : g[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            res[v] = res[u] + 1;
            dfs1(v);
        }
    }
}


void dfs2(int u, int d = 1) {
    vis[u] = 1;
    int v = p[u];
    if (vis[v]) {
        res[u] = d;
    } else {
        dfs2(v, d + 1);
        res[u] = res[v];
    }
    dfs1(u);
}

int main() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n; i++) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
        IN[p[i]]++;
    }
    for (int i = 1 ; i <= n; i++) {
        if (IN[i] == 0) q.push(i);
        vis[i] =0;

    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = p[u];
        IN[v]--;
        if (IN[v] == 0) {
            q.push(v);
        }
    }
    for (int i = 1; i<= n ;i++) {
        if (!vis[i] && IN[i]) {
            dfs2(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }





    return 0;
}
