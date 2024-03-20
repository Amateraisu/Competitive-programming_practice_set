#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using T = pair<ll, ll>;

constexpr ll INF = 1e18;
ll MOD = 1e9 + 7;

void dijkstra(vector<vector<T>>& g) {
    int n = g.size();
    vector<ll>distances(n, INF); // part A
    vector<ll>nums(n, 0); // part B
    vector<ll>mins(n, INF); // part C
    vector<ll>maxs(n, 0); // part D
    distances[0] = 0;
    nums[0] = 1;
    mins[0] = 0;
    maxs[0] = 0;
    vector<int>visited(n, 0);
    priority_queue<T, vector<T>, greater<T>>pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        if (visited[u.second] == 1) continue;
        visited[u.second] = 1;
        for (auto v : g[u.second]) {
            ll alt = u.first + v.second;
            if (alt == distances[v.first]) {
                nums[v.first] = (nums[v.first] + nums[u.second]) % MOD;
                mins[v.first] = min(mins[v.first], mins[u.second] + 1);
                maxs[v.first] = max(maxs[v.first], maxs[u.second] + 1);
            } else if (alt < distances[v.first]) {
                nums[v.first] = nums[u.second];
                mins[v.first] = mins[u.second] + 1;
                maxs[v.first] = maxs[u.second] + 1;
                distances[v.first] = alt;
                pq.push(make_pair(u.first + v.second, v.first));
            }
        }
    }
    cout << distances[n - 1] << ' ' << nums[n - 1] << ' ' << mins[n - 1] << ' ' <<maxs[n - 1] << '\n';


    return;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<T>>g(n);
    for (int i = 0 ;i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(make_pair(b, c));
    }
    dijkstra(g);



}
