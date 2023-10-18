#include <bits/stdc++.h>
constexpr int maxN = 1e5 + 1;
using namespace std;
constexpr int maxM = 2e5 + 1;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
int a, b, c;
int n, m;
using ll = long long;
using edge = tuple<ll, int>;
ll d[maxN];
vector<edge> g[maxN];

int main() {
    memset(d, INF, sizeof(d));
    scanf("%d %d", &n, &m);
    for  (int i  = 0; i < m ;i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back({c, b});
    }
    d[1] = 0;
    priority_queue<edge, vector<edge>, greater<edge>>pq; // [cost, node]
    pq.push({0, 1});
    while (!pq.empty()) {
        edge e = pq.top(); pq.pop();
        ll cost = get<0>(e);
        int u = get<1>(e);
        if (cost > d[u]) continue;
        for (auto e2: g[u]) {
            int v = get<1>(e2);
            int fees = get<0>(e2);
            if (fees + cost < d[v]) {
                d[v] = fees + cost;
                pq.push({fees + cost, v});
            }

        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", d[i]);
    }
    return 0;
}