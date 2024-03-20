#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
    int n, m , q;
    ll a, b, c;
    cin >> n >> m >> q;
    vector<vector<ll>>g(n, vector<ll>(n, INF));
    for (int i = 0 ; i < n; ++i)g[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a;
        --b;
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }


    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        --a;
        --b;
        if (g[a][b] != INF) {
            cout << g[a][b] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}
