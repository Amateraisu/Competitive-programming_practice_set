#include <bits/stdc++.h>
constexpr int maxN = 2e5 + 1;
using ll = long long;
using namespace std;
int p[maxN];
int res[maxN];
int n;
int vis[maxN];
vector<int> g[maxN];
int IN[maxN];
queue<int>q;

void dfs1(int curNode) {
    for (int x: g[curNode]) {
        if (vis[x] == 0) {
            vis[x] = 1;
            res[x] = res[curNode] + 1;
            dfs1(x);
        }
    }
}

void dfs2(int curNode, int d = 1) {
    vis[curNode] = 1;
    int v = p[curNode];
    if (vis[v]) {
        res[curNode] = d;
    } else {
        dfs2(v, d + 1);
        res[curNode] = res[v];
    }
    dfs1(curNode);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i<= n ;i++) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
        IN[p[i]]++;

    }
    for (int i = 1 ; i<= n; i++) {
        if (IN[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int v = p[u];
        IN[v]--;
        if (IN[v] == 0) q.push(v);
    }
    for (int i = 1; i <=n ;i++) {
        if (!vis[i] && IN[i]) dfs2(i);
    }

    for (int i = 1; i<= n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}
