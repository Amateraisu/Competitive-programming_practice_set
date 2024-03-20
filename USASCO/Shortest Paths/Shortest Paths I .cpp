#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>>g(n);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(make_pair(b, c));
    }
    using T = pair<ll, ll>;
    priority_queue<T, vector<T>, greater<T>>pq;
    vector<ll>distances(n, INF);
    vector<ll>v(n, -1);
    distances[0] = 0;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        if (v[u.second] == 1) continue;
        v[u.second] = 1;
        distances[u.second] = u.first;
        for (auto v : g[u.second]) {
            if (u.first + v.second < distances[v.first]) {
                pq.push(make_pair(u.first + v.second, v.first));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << distances[i] << ' ';
    }
    cout << '\n';
}
