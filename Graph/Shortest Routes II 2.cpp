#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = tuple<int, int>;
constexpr int maxN = 501;
constexpr int maxM = 501 * 501;
int n, m, q;
int a, b;
ll c;
ll dist[maxN][maxN];
vector<edge> g[maxN];
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int i =1; i <= n; i++) dist[i][i] =0;
    for (int k = 1; k <=n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);

            }
        }
    }
    for (int i = 0 ; i < q; i++) {
        scanf("%d %d", &a, &b);
        printf("%lld\n", dist[a][b] != INF ? dist[a][b] : -1);
    }





    return 0;
}