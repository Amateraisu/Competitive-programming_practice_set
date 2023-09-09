#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using ll = long long;
using namespace std;
int a, b;
int n = 2e5 + 1;

vector<vector<int>>g(n);

vector<ll> res(n, 0);
vector<ll>cnt(n, 0);

void dfs1(int u = 1, int p =  0) {
    cnt[u] = 1;
    for (int v: g[u]) {
        if (v != p) {
            dfs1(v, u);
            cnt[u] += cnt[v];
            res[u] += res[v] + cnt[v];
        }
    }
}

void dfs2(int u = 1, int p = 0) {

    for (auto x : g[u]) {
        if (x != p) {
            res[x] = res[u] - cnt[x] + n - cnt[x];
            dfs2(x, u);
        }
    }
}



int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1();
    dfs2();
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}
