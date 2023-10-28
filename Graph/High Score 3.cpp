#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int maxN = 2501;
constexpr int maxM = 5001;
constexpr ll INF = 0x3f3f3f3f3f3f3f;
ll dp[maxN];
int n, m;
int a, b;
ll c;
vector<int>g1[maxN];
vector<int>g2[maxN];
int v1[maxN];
int v2[maxN];
struct edge {
    int a;
    int b;
    ll c;
};
void dfs1(int u, int p = -1) {
    v1[u] = 1;
    for (int v: g1[u]) {
        if (v1[v] == 0 && p != v) {
            dfs1(v, u);
        }
    }
}

void dfs2(int u, int p = -1) {
    v2[u] = 1;
    for (int v: g2[u]) {
        if (v2[v] == 0 && p != v) {
            dfs2(v, u);
        }
    }
}



int main() {


    scanf("%d %d", &n , &m);
    fill(dp + 2, dp + n + 1, INF);
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &a, &b , &c);
        edges.push_back({a, b, -c});
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    dfs1(1);
    dfs2(n);
    bool improvement = true;
    for (int i = 0; i < n && improvement; i++) {
        improvement = false;
        for (int j = 0; j < m; j++) {
            edge e = edges[j];
            int u = e.a;
            int v = e.b;
            int cost = e.c;
            if (dp[v] > dp[u] + cost) {
                improvement = true;
                dp[v] = dp[u] + cost;
                if (i == n - 1 && v1[v] == 1 && v2[v] == 1) {
                    printf("%d", -1);
                    return 0;
                }
            }
        }
    }
    printf("%lld", -dp[n]);





    return 0;
}

