#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int>comp;

void dfs(int u, vector<int>& vis, map<int, vector<int>>& mp) {
    vis[u] = true;
    comp.push_back(u);
    for (int v : mp[u]) {
        if (!vis[v]) {
            dfs(v, vis, mp);
        }
    }
}


int main() {
    cin >> n >> m;
    vector<int>vis(n + 1, 0);
    map<int, vector<int>>mp;
    vector<int>in(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
        ++in[a];
        ++in[b];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            bool can  = true;
            comp.clear();
            dfs(i, vis, mp);
            for (int node: comp) {
                if (in[node] != 2) can = false;
            }
            if (can) ++res;
        }
    }

}
