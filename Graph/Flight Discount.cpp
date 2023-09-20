#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using edge = pair<int, ll>;
using node = tuple<ll, int, int>;

const int N = 2e5 + 1;
int n , m, a, b;
ll c, dist[2][N];
vector<edge> G[N];
priority_queue<node, vector<node>, greater<node>>q;

int main() {
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 0; i < m ; i++) {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }
    dist[0][1] = dist[1][1] = 0;
    q.push({0, 1, 1});
    while (!q.empty()) {
        ll d = get<0>(q.top());
        ll u = get<1>(q.top());
        ll coupon = get<2>(q.top());
        q.pop();
        if (dist[!coupon][u] < d) continue;
        for (edge e: G[u]) {
            int v = e.first;
            ll w = e.second;
            if (coupon) { // got coupon
                if (dist[0][v] > d + w) {
                    dist[0][v] = d + w;
                    q.push({d + w, v, 1});
                }
                if (dist[1][v] > d + w/2) {
                    dist[1][v] = d + w/2;
                    q.push({d + w/2, v, 0});
                }
            } else { // no coupon
                if (dist[1][v] > d + w) {
                    dist[1][v] = d + w;
                    q.push({d + w, v, 0});
                }

            }
        }
    }

    cout << min(dist[0][n] , dist[1][n]) << '\n';
    return 0;

}
