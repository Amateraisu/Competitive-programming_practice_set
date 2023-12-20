#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, t;
constexpr int maxN = 1e6 + 1;
int a, b;
int dfs2(int start, vector<vector<int>>& g) {
    int fin = -1;
    vector<int>q;
    set<int>vs;
    q.push_back(start);
    while (!q.empty()) {
        int u = q.front(); q.pop_back();
        fin = u;
        vs.insert(u);
        for (int v: g[u]) {
            if (vs.find(v) != vs.end()) q.push_back(v);
        }
    }
    return fin;
}
int dfs(int u, int p, vector<vector<int>>& g) {
    int res = 0;
    if (g[u].size() >= 3) {
        res += g[u].size() - 2;
    }
    for (int v : g[u]) {
        if (v == p) continue;
        res += dfs(v, u, g);
    }

    return res;
}


void test() {
    cin >> n;
    vector<vector<int>>g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int n1 = -1;
    int n2 = -1;
    int t1 = dfs2(1, g);
    n1 = dfs2(t1,g);
    n2 = dfs2(n1,g);
    int res = dfs(n2, -1, g);
    if (res == 0) {
        cout << 1 << '\n';
        return;
    }
    cout << res << '\n';
}


int main() {
    cin >> t;
    while (t--) test();
}
