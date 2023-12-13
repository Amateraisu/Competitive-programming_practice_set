#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
int x;
int a, b;

int dfs(int u, int p, int catC, vector<int>& dp, map<int, vector<int>>& mp, vector<int>& deg,vector<int>& cat) {

    if (dp[u] != -1) return dp[u];
    int newC = catC;
    if (cat[u]) {
        ++newC;
    } else {
        newC = 0;
    }
    if (newC > m) return 0;
    if (deg[u] == 1 && u != 1)  {
        return 1;
    }
    int res = 0;
    for (int v: mp[u]) {

        if (v != p) res += dfs(v, u, newC, dp, mp, deg, cat);

    }

    dp[u] = res;
    return dp[u];
}

int main() {
    cin >> n >> m;
    vector<int>cat(n + 1, 0);
    vector<int>deg(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x) cat[i] = 1;

    }
    map<int, vector<int>>mp;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
        ++deg[a];
        ++deg[b];
    }
    vector<int>dp(n + 1, -1);
    int res = dfs(1, -1, 0, dp, mp, deg, cat); // current tree
    cout << res << '\n';

}
