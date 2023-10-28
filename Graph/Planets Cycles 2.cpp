#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxN = 2e5 + 1;
vector<int> g1[maxN];
vector<int> g2[maxN];
int vis1[maxN];
int vis2[maxN];
int c = 0;
vector<int> components[maxN];
int belong[maxN];
int n, a, b, m;
stack<int>s;

void dfs1(int u, int p = -1) {
    vis1[u] = 1;
    for (int v: g1[u]) {
        if (vis1[v] == 0 && v != p) {
            dfs1(v, u);
        }
    }
    s.push(u);
}

void dfs2(int u , int p = -1) {
    vis2[u] = 1;
    components[c].push_back(u);
    belong[u] = c;
    for (int v: g2[u]) {
        if (vis2[v] == 0 && v != p) {
            dfs2(v, u);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    // use k's algo
    for (int i = 1 ; i <= n; i++) {
        if (vis1[i] == 0) {
            dfs1(i);
        }
    }
    while (!s.empty()) {

        int u = s.top(); s.pop();
        if (vis2[u] == 1) continue;
        dfs2(u);
        c++;
    }
    printf("%d\n", c);
    for (int i = 1; i<= n; i++) {
        printf("%d ",  static_cast<int>(belong[i]) + 1);
    }

    return 0;
}