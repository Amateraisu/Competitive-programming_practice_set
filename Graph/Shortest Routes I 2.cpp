#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
    ll cost;
    int node;
    edge(ll c, int n): cost(c), node(n) {}
    bool operator > (const edge& other) const {
        return cost > other.cost;
    }
};
constexpr int maxN = 1e5 + 1;
constexpr int maxM = 2e5 + 1;
vector<edge> g[maxN];
ll INF = 0x3f3f3f3f3f3f3f3f;
ll dist[maxN];

int n, m, a, b;
ll c;
int main() {
    memset(dist, INF, sizeof(dist));
    scanf("%d %d", &n , &m);
    priority_queue<edge, vector<edge>, greater<edge>>pq;
    pq.push(edge(0, 1));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        g[a].push_back(edge(c, b));
    }


    while (!pq.empty()) {
        edge e = pq.top(); pq.pop();
        if (e.cost > dist[e.node]) continue;
        dist[e.node] = e.cost;
        for (edge nei: g[e.node]) {
            ll newCost = e.cost + nei.cost;
            int v = nei.node;
            pq.push(edge(newCost, v));
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%lld ", dist[i]);
    }

    return 0;
}
