#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
ll n, q, a, b;
vector<vector<int>>dp(200005, vector<int>(32, 0));
vector<int>lvl(200005, 0);



void dfs(int u = 1, par = 1) {

}

int liftNode(int node, int k) {
    for (int i = 19; i >= 0; i--) {
        if (k & (1 << i)) {
            node = dp[node][i];
        }
    }
    return node;
}


int LCA2(int u, int v) {
    if (lvl[u] < lvl[v]) swap(u, v);
    // make u the deeper one
    u = liftNode(u, lvl[u] - lvl[v]); // then climb u
    if (u == v) return u;

    for (int i = 19; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return liftNode(u, 1);
}


int main() {

    cin >> n >> q;
    // build binary lifitng
    int bits = 32;
    for (int i = 2; i < n + 1; i++) {
        cin >> dp[i][0];
    }
    // build
    for (int j = 1; j < bits; j++) {
        for (int i = 2; i <= n ; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
    dfs();
    for (int i = 0; i < q; i++) {

    }


    return 0;
}