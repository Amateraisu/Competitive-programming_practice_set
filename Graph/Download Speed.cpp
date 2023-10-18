#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using edge = pair<int, ll>;
constexpr int maxN = 500 + 1;
constexpr int maxM = 1000 + 1;
vector<int> g[maxN];
int a, b, n, m;
ll c;
ll cap[maxN][maxN];
int p[maxN];
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

ll bfs(int s = 1, int t = n) {
    fill(p + 1, p + n + 1, -1);
    p[s] = -2;
    queue<edge>q;
    q.push({1, INF});
    while (!q.empty()) {
        int u = q.front().first;
        ll f = q.front().second;
        q.pop();
        for (int v : g[u]) {
            if (p[v] == -1 && cap[u][v]) {
                p[v]= u;
                ll aug = min(f, cap[u][v]);
                if (v == t) return aug;
                q.push({v, aug});
            }
        }
    }
    return 0;
}

ll maxflow(int s = 1, int t = n) {
    ll flow = 0;
    ll aug = 0;
    while (aug = bfs()) {
        flow += aug;
        int u = t;
        while (u != s) {
            int v = p[u];
            cap[u][v] += aug;
            cap[v][u] -= aug;
            u = v;
        }
    }


    return flow;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < m ; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back(b);
        g[b].push_back(a);
        cap[a][b]+= c;
    }
    printf("%lld", maxflow());
    return 0;
}
