#include <bits/stdc++.h>
using namespace std;
constexpr int maxN = 2e5 + 1;
int vis[maxN];
int c1[2][maxN];

int n, a, b;
vector<int>g[maxN];

int bfs(int start, int c) {
    queue<int>q;
    int end = start;
    q.push(start);
    c1[c][start] = 0;
    while (!q.empty()) {
        int u = q.front();q.pop();
        vis[u] = 1;
        for (int v: g[u]) {
            if (vis[v] == 0) {
                c1[c][v] = c1[c][u] + 1;
                vis[v] = 1;
                q.push(v);
                end = v;
            }
        }
    }
    return end;
}



int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int n1 = bfs(1,1);
    memset(vis, 0, sizeof(vis));
    int n2 = bfs(n1, 0);
    memset(vis, 0, sizeof(vis));
    bfs(n2, 1);
    for (int i = 1; i <= n; i++) {
        printf("%d ", max(c1[0][i], c1[1][i]));
    }



    return 0;
}
