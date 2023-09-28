#include <bits/stdc++.h>
constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;
using ll = long long;
using namespace std;
int n, m, a, b;
int l[maxN];
vector<int> g[maxN];
int IN[maxN];
queue<int> q;
int p[maxN];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <=n; i++) {
        l[i] = -1;
    }
    for (int i = 1; i<=m; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        IN[b]++;
    }
    l[1] = 0;
    for (int i = 1; i<= n; i++) {
        if (IN[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (l[u] != -1 && l[u] + 1 > l[v]) {
                l[v] = l[u] + 1;
                p[v] = u;
            }
            IN[v]--;
            if (IN[v] == 0) q.push(v);
        }
    }
    if (l[n] == -1) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int k = l[n] - l[1];
    vector<int>res;
    int u = n;
    for (int i = 0; i < k ;i++) {
        res.push_back(u);
        u = p[u];
    }
    reverse(res.begin(), res.end());
    printf("%d\n" ,k + 1);
    printf("%d ", 1);
    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }

    return 0;
}