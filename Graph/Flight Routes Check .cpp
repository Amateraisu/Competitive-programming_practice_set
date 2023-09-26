#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;
// go through all nodes, do a dfs on all nodes
int vis1[maxN];
int vis2[maxN];
vector<int> g1[maxN], g2[maxN];

void dfs1(int u = 1, int p = 0) {
    vis1[u]  = 1;
    for (int v : g1[u]) {
        if (!vis1[v] && v != p) {
            dfs1(v, u);
        }
    }


}

void dfs2(int u = 1, int p = 0) {
    vis2[u]  = 1;
    for (int v : g2[u]) {
        if (!vis2[v] && v != p) {
            dfs2(v, u);
        }
    }
}
int n , q, a, b;
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &a , &b);
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    for (int i = 1; i<= n; i++) {
        vis1[i] = 0;
        vis2[i] = 0;
    }
    dfs1();
    dfs2();
    for (int i = 1; i <= n; i++) {
        if (!vis1[i] || !vis2[i]) {
            printf("NO\n");
            if (!vis1[i]) {

                printf("1 %d\n", i);
            } else {
                printf("%d 1\n", i);
            }
            return 0;
        }

    }

    printf("YES\n");




    return 0;
}
