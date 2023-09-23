#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
using edge = tuple<int, ll>;
ll n, m, c;
int a, b;
constexpr ll maxN = 1e5 + 1;
constexpr ll manM = 2e5 + 1;
const ll INF = 0x3f3f3f3f3f3f3f3f;

vector<edge> g[maxN];
int p[maxN];
ll dp[maxN];
priority_queue<edge, vector<edge> , greater<edge>>pq;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    for (int i =1 ; i<= n; i++) {
        dp[i] = INF;
    }
    pq.push({0, 1});
    while (!pq.empty()) {
        edge e = pq.top();
        int cost = get<0>(e);
        int u = get<1>(e);
        if (cost > dp[u]) continue;
        for (edge ed: g[u]) {
            int v = get<0>(ed);
            int dol = get<1>(ed);
            if (dol + cost < dp[v]) {
                dp[v] = dol + cost;
                pq.push({dol + cost, v});
            }
        }
    }
    int target = dp[n];
    for (int i =1 ; i<= n; i++) {
        dp[i] = INF;
    }
    pq.push({0, 1});
    while (!pq.empty()) {
        edge e = pq.top();
        int cost = get<0>(e);
        int u = get<1>(e);
        if (cost > dp[u]) continue;
        if (u == n && cost == target)
        for (edge ed: g[u]) {
            int v = get<0>(ed);
            int dol = get<1>(ed);
            if (dol + cost < dp[v]) {
                dp[v] = dol + cost;
                pq.push({dol + cost, v});
            }
        }
    }





    return 0;
}
