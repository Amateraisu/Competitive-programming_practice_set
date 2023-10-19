#include <bits/stdc++.h>
using namespace std;
constexpr int maxN = 1e5 + 1;
int IN[maxN];
vector<int> g[maxN];
int n, m;
int vis[maxN];
int a, b;
queue<int>q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        IN[b]++;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (IN[i] == 0) {
            q.push(i);
        }
    }
    vector<int>res;
    while (!q.empty()) {
        c++;
        int u = q.front(); q.pop();
        res.push_back(u);
        for (int v: g[u]) {
            IN[v]--;
            if (IN[v] == 0) {
                q.push(v);
            }
        }
    }
    if (c != n) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
