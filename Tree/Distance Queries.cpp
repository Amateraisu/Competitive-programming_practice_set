#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;


ll n = 2e5;
vector<ll>l(n + 1, 0);
vector<vector<ll>>dp(n + 1, vector<ll>(32, 0));
vector<vector<ll>>g(n + 1);
vector<ll>bosses(n + 1, 0);
ll q, a, b, x;

void dfs(int current = 1, int parent = 0, int lvl = 0) {
    dp[current][0] = parent;
    l[current] = lvl;
    for (int nei : g[current]) {
        if (nei != parent) dfs(nei, current, lvl + 1);
    }

}

int find(int node1, int node2) {

    if (l[node1] < l[node2]) swap(node1, node2);

    int diff = l[node1] - l[node2];
    for (int i = 20; i >= 0; i--) {
        if (diff & (1 << i)) {
            node1 = dp[node1][i];
        }
    }
    if (node1 == node2) return node1;
    for (int i = 20; i >= 0; i--) {
        if (dp[node1][i] != dp[node2][i]) {
            node1= dp[node1][i];
            node2= dp[node2][i];
        }
    }
    return dp[node1][0];
}



int main() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j < 20; j++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        int lca = find(a, b);
        int res = l[a] + l[b] - 2 * l[lca];
        // cout << "DEBUGGING " << a << ' ' << b << ' ' << lca << '\n';
        // cout << l[a] << ' ' << l[b] << ' ' << l[lca] << '\n';
        cout << res << '\n';
    }

    return 0;
}