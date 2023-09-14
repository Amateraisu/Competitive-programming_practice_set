#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <climits>
using ll = long long;
using namespace std;
ll n = 1e5;
ll m = 2e5;
vector<ll>vis(n + 1, INT_MAX);
vector<vector<pair<ll, ll>>>g(n + 1, vector<pair<ll, ll>>());
ll a, b, c;



int main() {

    cin >> n >> m;
    for (ll i = 0; i < m; i ++) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }
    priority_queue<pair<ll , ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>>pq;

    pq.push({0, 1});
    vis[1] = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        ll cost = top.first;
        ll cur = top.second;
        for (auto x : g[cur]) {
            ll co = x.second;
            ll nei = x.first;
            ll newCo = co + cost;
            if (newCo < vis[nei]) {
                vis[nei] = newCo;
                pq.push({newCo, nei});
            }
        }
    }


    for (ll i = 1; i <= n; i++) {
        cout << vis[i] << ' ';
    }




    return 0;
}