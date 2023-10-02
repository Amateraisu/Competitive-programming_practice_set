#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, a, b;
constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;
vector<int> g[maxN];
int v1[maxN]; // visitied
int v2[maxN];

bool dfs(int u , int c) {
    if (v1[u] != 0) {
        return c ==  v1[u];
    }
    v1[u] = c;
    bool current = true;
    for (int v : g[u]) {
        if (c == 1) {
            current &= dfs(v, 2);
        } else {
            current &= dfs(v, 1);
        }
    }
    return current;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <=n; i++) {
        if (!v1[i]) {
            bool can = dfs(i, 1);
            if (!can) {
                printf("IMPOSSIBLE\n");
                return 0;
            }
        }
    }
    for (int i = 1; i <=n; i++) {
        printf("%d ", v1[i]);
    }



    return 0;
}