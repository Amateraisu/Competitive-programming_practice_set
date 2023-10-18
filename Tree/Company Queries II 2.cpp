#include <bits/stdc++.h>
using ll = long long;
using namespace std;


ll n = 2e5;
vector<ll>l(n + 1, 0);
vector<vector<ll>>dp(n + 1, vector<ll>(32, 0));
vector<vector<ll>>g(n + 1);
vector<ll>bosses(n + 1, 0);
ll q, a, b, x;

void dfs(int current = 1, int parent = -1, int lvl = 0) {

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
    for (int i = 2; i <= n; i++) {
        cin >> x;
        bosses[i] = x;
        g[x].push_back(i);
    }
    dfs();
    // set up dp
    for (int i = 2; i <= n; i++) {
        dp[i][0] = bosses[i];
    }
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j < 20; j++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << find(a , b) << '\n';
    }

    return 0;
}
