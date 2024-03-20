#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using T = pair<ll, ll>;
using TU = std::tuple<ll, ll, ll>; // cost, has used, node

constexpr ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<T>>g(n);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(make_pair(b, c));
    }
    vector<vector<ll>>distances(2, vector<ll>(n, INF));
    vector<vector<int>>visited(2, vector<int>(n, 0));
    distances[0][0] = 0;
    priority_queue<TU, vector<TU>, greater<TU>>pq;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
        auto f = pq.top(); pq.pop();
        ll u = get<2>(f);
        ll hasUsed = get<1>(f);
        ll cost = get<0>(f);
        if (visited[hasUsed][u] == 1) continue;
        visited[hasUsed][u] = 1;
        if (hasUsed == 0) {
            // can decide to use
            for (auto nei : g[u]) {
                ll v = nei.first;
                ll cost2 = nei.second;
                ll discounted = cost2/2;
                if (cost + cost2 < distances[0][v]) {
                    distances[0][v] = cost + cost2;
                    pq.push({cost + cost2, 0, v});
                }
                if (cost + discounted < distances[1][v]) {
                    distances[1][v] = cost + discounted;
                    pq.push({cost + discounted, 1, v});
                }
            }

        } else {
            for (auto nei: g[u]) {
                ll v = nei.first;
                ll cost2 = nei.second;
                if (cost + cost2 < distances[1][v]) {
                    distances[1][v] = cost + cost2;
                    pq.push({cost + cost2, 1, v});
                }
            }

            // cannot use at all.

        }
    }
    cout << distances[1][n - 1] << '\n';


}
